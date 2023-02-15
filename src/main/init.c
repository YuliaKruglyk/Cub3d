/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:07:07 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/15 21:20:24 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_game(t_cub3d *game)
{
	int	i;

	game->map_hght = 0;
	game->map_h_tmp = 0;
	i = -1;
	while (++i < 4)
	{
		game->file_name[i] = NULL;
		game->texture[i].img = NULL;
	}
	game->window = NULL;
	game->ceil_col = 13167335;
	game->floor_col = 5257270;
	game->map_comp = NULL;
	game->ceil_col = 0;
	game->floor_col = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->mlx = mlx_init();
}
