/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:49:39 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/31 16:45:14 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		x_len;
	int		y_len;
	void	*img;
	void	*param;
	int		p_x;
	int		p_y;
}				t_data;

typedef struct s_point
{
	int		c_x;
	int		c_y;
	int		e_x;
	int		e_y;
	int		wall_x;
	int		wall_y;
	int		c_num;
}				t_point;

typedef struct s_pics
{
	void	*p_img;
	void	*zero_img;
	void	*wall_img;
	void	*c_img;
	void	*e_img;
}				t_pics;

typedef struct s_flags
{
	int		do_flag;
	int		w_flag;
	int		a_flag;
	int		s_flag;
	int		d_flag;
	int		c_flag[3600];
	int		cx_flag[3600];
	int		cy_flag[3600];
}				t_flags;

typedef struct s_game
{
	t_data	data;
	t_point	point;
	t_pics	pics;
	t_flags	flags;
	char	*argv;
	int		er_len[2];
	int		c_count;
	int		mv_count;
	int		p_ch;
	int		e_ch;
	int		c_ch;
}				t_game;

t_game	*free_game(void);
void	do_p(t_game *game);
void	do_e(t_game *game);
void	do_c(t_game *game);
void	do_wall(t_game *game);
void	find_c(t_game *game);
void	nulling(t_game *game);
int		checker(t_game *game);
void	map_symbols(t_game *game, char *buf, int fd);
void	parser(char *buf, t_game *game, int fd);
void	map_format_error(char *argv);
void	map_size_error(t_game *game, int a);
void	ft_error(t_game *game, int fd);
void	wall_checker(t_game *game);
void	reader(t_game *game);
void	background(t_game *game);
void	mv_counter(t_game *game);
void	moving(t_game *game, int a);
int		wasd(int keycode, t_game *game);
int		window(t_game *game);
int		game_end(t_game *game);
void	points_check(t_game *game, int fd);

#endif