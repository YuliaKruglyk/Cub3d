/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:07:07 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/19 17:57:09 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_game(t_cub3d *game)
{
	game->map_hght = 0;
	game->map_h_tmp = 0;
	
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// {
	// 	ft_putstr_fd("Error\nCannot allocate memory for mlx\n", 2);
	// 	exit(1);
	// }
}
