/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:48:14 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/31 16:38:19 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_p(t_game *game)
{
	int		wid;
	int		hei;

	if (!game->flags.do_flag)
	{
		game->data.p_y = game->data.y_len * 64 - 64;
		game->data.p_x = game->data.x_len * 64 - 64;
	}
	if (game->flags.do_flag)
	{
		game->pics.p_img = mlx_xpm_file_to_image(game->data.mlx,
				 "./pics/pers.xpm", &wid, &hei);
		mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
			 game->pics.p_img, game->data.p_x, game->data.p_y);
	}
	game->p_ch = 1;
}

void	do_e(t_game *game)
{
	int		wid;
	int		hei;

	if (!game->flags.do_flag)
	{
		game->point.e_y = game->data.y_len * 64 - 64;
		game->point.e_x = game->data.x_len * 64 - 64;
	}
	if (game->flags.do_flag)
	{
		game->pics.e_img = mlx_xpm_file_to_image(game->data.mlx,
				 "./pics/exit.xpm", &wid, &hei);
		mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
			 game->pics.e_img, game->point.e_x, game->point.e_y);
	}
	game->e_ch = 1;
}

void	find_c(t_game *game)
{
	int		a;

	a = 0;
	while (a != game->point.c_num + 1)
	{
		if (game->flags.cx_flag[a] == game->data.p_x && game->flags.cy_flag[a]
			 == game->data.p_y && game->flags.c_flag[a] != 1)
			game->c_count--;
		if (game->flags.cx_flag[a] == game->data.p_x
			 && game->flags.cy_flag[a] == game->data.p_y)
			game->flags.c_flag[a] = 1;
		a++;
	}
}

void	do_c(t_game *game)
{
	int		wid;
	int		hei;

	if (!game->flags.do_flag)
		game->c_count++;
	if (game->flags.do_flag)
	{
		game->point.c_num++;
		find_c(game);
		if (game->flags.c_flag[game->point.c_num] != 1)
		{
			game->point.c_y = game->data.y_len * 64 - 64;
			game->point.c_x = game->data.x_len * 64 - 64;
			game->flags.cx_flag[game->point.c_num] = game->point.c_x;
			game->flags.cy_flag[game->point.c_num] = game->point.c_y;
			game->pics.c_img = mlx_xpm_file_to_image(game->data.mlx,
					"./pics/coin.xpm", &wid, &hei);
			mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
				game->pics.c_img, game->point.c_x, game->point.c_y);
		}
	}
	game->c_ch = 1;
}

void	do_wall(t_game *game)
{
	int		wid;
	int		hei;

	if (game->flags.do_flag)
	{
		game->point.wall_y = game->data.y_len * 64 - 64;
		game->point.wall_x = game->data.x_len * 64 - 64;
		game->pics.wall_img = mlx_xpm_file_to_image(game->data.mlx,
				"./pics/wall.xpm", &wid, &hei);
		mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
			game->pics.wall_img, game->point.wall_x, game->point.wall_y);
	}
}
