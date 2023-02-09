/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:46:52 by ykruhlyk          #+#    #+#             */
/*   Updated: 2023/02/09 16:36:46 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_destroy_image(t_cub3d *game)
{
	int	i;

	i = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	while (i <= 3)
	{
		if (game->texture[i].img)
			mlx_destroy_image(game->mlx, game->texture[i].img);
		i++;
	}
	free_map_comp2(game);
	exit(0);
}

void	init_image(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = \
		mlx_xpm_file_to_image(game->mlx, game->file_name[i],
				&game->texture[i].width, &game->texture[i].height);
		game->texture[i].adrs = mlx_get_data_addr(game->texture[i].img,
				&game->texture[i].bits, &game->texture[i].line_len,
				&game->texture[i].b_order);
		i++;
	}
}
