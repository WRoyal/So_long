/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:48:35 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/31 15:03:07 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_symbols(t_game *game, char *buf, int fd)
{
	char	*sym;

	sym = "10PCE";
	while (*sym != '\0')
	{
		if (*buf == *sym || *buf == '\n' || *buf == '\0')
			return ;
		sym++;
	}
	printf("Error\n%s\n", "ONLY 0 1 P C E");
	close(fd);
	free(game);
	exit(0);
}

void	map_format_error(char *argv)
{
	char	*ber;

	ber = ".ber";
	while (*argv != '.')
		argv++;
	while (*argv != '\0')
	{
		if (*argv != *ber)
		{
			printf("Error\n%s\n", "Map format is wrong, example: // map.ber //");
			exit(0);
		}
		argv++;
		ber++;
	}
}

void	map_size_error(t_game *game, int a)
{
	game->er_len[0] = game->data.x_len;
	if (a == 0)
		game->er_len[0] += 1;
	if (game->er_len[0] != game->er_len[1] && game->er_len[1] != 0)
	{
		printf("Error\n%s\n", "Different line sizes");
		free(game);
		exit (0);
	}
	game->er_len[1] = game->data.x_len;
}

void	ft_error(t_game *game, int fd)
{
	close(fd);
	printf("Error\n%s\n", "There must be walls around the perimeter of the map");
	free(game);
	exit(0);
}

void	wall_checker(t_game *game)
{
	char	buf[1];
	char	ret;
	int		fd;
	int		count;

	count = 0;
	fd = open(game->argv, O_RDONLY);
	while (read(fd, buf, 1) && buf[0] != '\n')
		if (buf[0] != '1' && buf[0] != '\n')
			ft_error(game, fd);
	ret = buf[0];
	while (read(fd, buf, 1) && count != game->data.y_len - 2)
	{
		if (buf[0] == '\n')
			count++;
		if ((buf[0] == '\n' && ret != '1') || (ret == '\n' && buf[0] != '1'))
			ft_error(game, fd);
		ret = buf[0];
	}
	while (read(fd, buf, 1))
		if (buf[0] != '1')
			ft_error(game, fd);
	close(fd);
}
