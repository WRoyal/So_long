/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:48:05 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/31 16:44:14 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*free_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->data.y_len = 1;
	game->mv_count = 0;
	game->c_count = 0;
	return (game);
}

void	nulling(t_game *game)
{
	if (game->flags.do_flag)
	{
		game->data.x_len = 0;
		game->data.y_len = 1;
	}
	game->er_len[0] = 0;
	game->er_len[1] = 0;
	game->point.c_num = 0;
	game->flags.w_flag = 0;
	game->flags.a_flag = 0;
	game->flags.s_flag = 0;
	game->flags.d_flag = 0;
	game->p_ch = 0;
	game->e_ch = 0;
	game->c_ch = 0;
}

void	background(t_game *game)
{
	int		x;
	int		y;
	int		wid;
	int		hei;

	x = 0;
	y = 0;
	game->pics.zero_img = mlx_xpm_file_to_image(game->data.mlx,
			"./pics/zero.xpm", &wid, &hei);
	while (x != game->data.x_len && y != game->data.y_len)
	{
		while (x != game->data.x_len)
		{
			mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
				game->pics.zero_img, 64 * x, y * 64);
			x++;
		}
		x = 0;
		y += 1;
	}
}

void	mv_counter(t_game *game)
{
	int		a;

	a = 0;
	while (a++ != 20)
		write(1, "\n", 1);
	if (game->mv_count < 10)
		printf("%s %d %s\n", "\\\\Number Of Moves//\n//      ", game->mv_count,
			 "      \\\\");
	if (game->mv_count >= 10 && game->mv_count < 100)
		printf("%s %d %s\n", "\\\\Number Of Moves//\n//     ", game->mv_count,
			 "      \\\\");
	if (game->mv_count >= 100)
		printf("%s %d %s\n", "\\\\Number Of Moves//\n//     ", game->mv_count,
			 "     \\\\");
}

int	game_end(t_game *game)
{
	free(game);
	exit(0);
	return (0);
}
