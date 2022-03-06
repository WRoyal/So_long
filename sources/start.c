/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:48:21 by wroyal            #+#    #+#             */
/*   Updated: 2021/09/05 13:41:27 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(t_game *game)
{
	if (game->data.p_y - 64 == game->point.wall_y
		&& game->data.p_x == game->point.wall_x)
		game->flags.w_flag = 1;
	if (game->data.p_x - 64 == game->point.wall_x
		&& game->data.p_y == game->point.wall_y)
		game->flags.a_flag = 1;
	if (game->data.p_y + 64 == game->point.wall_y
		&& game->data.p_x == game->point.wall_x)
		game->flags.s_flag = 1;
	if (game->data.p_x + 64 == game->point.wall_x
		&& game->data.p_y == game->point.wall_y)
		game->flags.d_flag = 1;
	if (game->data.p_x == game->point.e_x
		&& game->data.p_y == game->point.e_y
		&& game->flags.do_flag && !game->c_count)
	{
		printf("     YOU WIN!\n");
		mlx_destroy_window(game->data.mlx, game->data.mlx_win);
		free(game);
		exit(0);
	}
	return (0);
}

void	parser(char *buf, t_game *game, int fd)
{
	map_symbols(game, buf, fd);
	if (*buf == '1')
		do_wall(game);
	if (*buf == 'C')
		do_c(game);
	if (*buf == 'E')
		do_e(game);
	if (*buf == 'P')
		do_p(game);
	checker(game);
	if (game->data.x_len > 40 || game->data.y_len > 22)
	{
		printf("Error\n%s\n", "Big map, make it smaller");
		close(fd);
		free(game);
		exit(0);
	}
}

void	reader(t_game *game)
{
	char	buf[1];
	int		fd;

	nulling(game);
	fd = open(game->argv, O_RDONLY);
	if (fd <= 0)
	{
		printf("Error\nThe file does not open\n");
		exit(0);
	}
	while (read(fd, buf, 1))
	{
		game->data.x_len += 1;
		if (buf[0] == '\n')
		{
			map_size_error(game, 1);
			game->data.x_len = 0;
			game->data.y_len += 1;
		}
		parser(buf, game, fd);
	}
	points_check(game, fd);
	map_size_error(game, 0);
	close(fd);
}

void	points_check(t_game *game, int fd)
{
	if (game->p_ch != 1 || game->c_ch != 1 || game->e_ch != 1)
	{
		printf("Error\nCheck map, it must have P and C and E\n");
		free(game);
		close(fd);
		exit(0);
	}
}

int	window(t_game *game)
{
	game->flags.do_flag = 1;
	game->data.mlx = mlx_init();
	game->data.mlx_win = mlx_new_window(game->data.mlx, 64 * game->data.x_len,
			64 * game->data.y_len, "so_long");
	background(game);
	reader(game);
	mlx_loop_hook(game->data.mlx, checker, game);
	mlx_hook(game->data.mlx_win, 17, 0, game_end, game->pics.p_img);
	mlx_key_hook(game->data.mlx_win, wasd, game);
	mlx_loop(game->data.mlx);
	return (0);
}
