/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:57:17 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/19 17:55:11 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	cub3d(const char *map, int fd)
{
	t_cub3d	*game;

	game = ft_calloc(sizeof(t_cub3d), 1);
	init_game(game);
	if (parsing_map(game, map, fd))
		exit(EXIT_FAILURE);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (allerrors(1));
	if (check_map_exten(argv[1]))
		return (allerrors(3));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (allerrors(2));
	if (cub3d(argv[1], fd))
	{
		// close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (0);
}
