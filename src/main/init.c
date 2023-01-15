/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:07:07 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/15 16:52:44 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_game(t_cub3d *game)
{
	int	i;

	game->map_hght = 0;
	game->map_h_tmp = 0;
	i = -1;
	while (++i < 5)
		game->texture[i].ptr = NULL;
	
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// {
	// 	ft_putstr_fd("Error\nCannot allocate memory for mlx\n", 2);
	// 	exit(1);
	// }
}
