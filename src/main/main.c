/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:57:17 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/04 13:37:33 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

void	free_tex(t_cub3d *game)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (game->file_name[i])
			free(game->file_name[i]);
	}
}

int	cub3d(const char *map, int fd)
{
	t_cub3d	*game;

	game = ft_calloc(sizeof(t_cub3d), 1);
	init_game(game);
	game->mlx = mlx_init();
	if (parsing_map(game, map, fd))
		exit(EXIT_FAILURE);
	init_image(game);
	ft_printf("images inited\n.......\n");
	game->window = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3d");

	build_window(game);

	mlx_hook(game->window, 2, 0, keys, game);
	mlx_hook(game->window, 17, 0, ft_destroy_image, game);
	mlx_loop(game->mlx);
	// free_map_comp2(game);
	// free_tex(game);
	// free(game);
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
