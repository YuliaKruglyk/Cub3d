/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:12 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/09 14:00:45 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Function to check map
int	check_map(t_cub3d *game)
{
	int	i;

	game->map_lnght = ft_strlen1(game->map_comp[0]);
	i = -1;
	while (++i < game->map_hght)
	{
		if (game->map_lnght < ft_strlen1(game->map_comp[i]))
			game->map_lnght = ft_strlen1(game->map_comp[i]);
	}
	if (check_chars(game) || border_check(game))
		return (free_map_comp_err(game));
	return (EXIT_SUCCESS);
}

//Function that check extension of the map
int	check_map_exten(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		return (allerrors(2));
	return (EXIT_SUCCESS);
}
