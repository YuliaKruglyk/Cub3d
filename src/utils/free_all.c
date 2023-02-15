/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:28:08 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/15 21:22:05 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	free_map_comp_err(t_cub3d *game)
{
	int	tmp_hght;

	tmp_hght = -1;
	while (++tmp_hght < game->map_hght)
	{
		if (game->map_comp[tmp_hght])
			free(game->map_comp[tmp_hght]);
	}
	if (game->map_comp)
		free(game->map_comp);
	return (allerrors(9));
}

void	free_map_comp2(t_cub3d *game)
{
	int	tmp_hght;

	tmp_hght = -1;
	while (++tmp_hght < game->map_hght)
	{
		if (game->map_comp[tmp_hght])
			free(game->map_comp[tmp_hght]);
	}
	if (game->map_comp)
		free(game->map_comp);
}
