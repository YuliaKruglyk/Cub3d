/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:57:17 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/13 13:04:54 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

void	free_tex(t_cub3d *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->file_name[i])
			free(game->file_name[i]);
	}
	if (game)
		free(game);
}

static int	check_player(t_cub3d *game)
{
	if (!game->player_x && !game->player_y)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	cub3d(const char *map, int fd)
{
	t_cub3d	*game;

	game = ft_calloc(sizeof(t_cub3d), 1);
	init_game(game);
	game->mlx = mlx_init();
	if (parsing_map(game, map, fd))
	{
		free_tex(game);
		exit(EXIT_FAILURE);
	}
	if (check_player(game))
	{
		allerrors2(15);
		exit(EXIT_FAILURE);
	}
	init_image(game);
	game->window = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3d");
	build_window(game);
	mlx_hook(game->window, 2, 0, keys, game);
	mlx_hook(game->window, 17, 0, ft_destroy_image, game);
	mlx_loop(game->mlx);
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
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (0);
}
