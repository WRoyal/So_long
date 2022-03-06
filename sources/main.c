/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:41:03 by wroyal            #+#    #+#             */
/*   Updated: 2021/08/31 16:27:13 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		map_format_error(argv[1]);
		game = free_game();
		game->argv = argv[1];
		reader(game);
		wall_checker(game);
		window(game);
	}
	else
		printf("Error\nCheck arguments, example: // ./so_long map.ber //\n");
	return (0);
}
