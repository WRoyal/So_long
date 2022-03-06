/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:47:48 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/23 19:47:58 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wasd(int keycode, t_game *game)
{
	reader(game);
	if (keycode == 53)
		exit(0);
	if (keycode == 13 && !game->flags.w_flag)
		moving(game, 1);
	if (keycode == 1 && !game->flags.s_flag)
		moving(game, 2);
	if (keycode == 0 && !game->flags.a_flag)
		moving(game, 3);
	if (keycode == 2 && !game->flags.d_flag)
		moving(game, 4);
	do_p(game);
	return (0);
}

void	moving(t_game *game, int a)
{
	mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
		game->pics.zero_img, game->data.p_x, game->data.p_y);
	if (game->data.p_x == game->point.e_x && game->data.p_y
		 == game->point.e_y && game->flags.do_flag)
		mlx_put_image_to_window(game->data.mlx, game->data.mlx_win,
			game->pics.e_img, game->data.p_x, game->data.p_y);
	if (a == 1)
		game->data.p_y -= 64;
	if (a == 2)
		game->data.p_y += 64;
	if (a == 3)
		game->data.p_x -= 64;
	if (a == 4)
		game->data.p_x += 64;
	game->mv_count++;
	mv_counter(game);
}
