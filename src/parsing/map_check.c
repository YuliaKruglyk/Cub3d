/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:16:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/23 14:54:00 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map_exten(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		return (allerrors(2));
	return (EXIT_SUCCESS);
}

static void	init_hero_pos(t_cub3d *game, int y, int x)
{
	game->player_x = x;
	game->player_y = y;
	ft_printf("\nPLAYER: %c\n", game->map_comp[y][x]);
	ft_printf("player x : %d, player y : %d\n", x, y);
}

int	check_chars(t_cub3d *game)
{
	int	i;
	int	j;
	int	hero;

	hero = 0;
	i = -1;
	while (++i < game->map_hght)
	{
		j = -1;
		while (game->map_comp[i][++j] != '\0')
		{
			// ft_printf("HEre: %c\n", game->map_comp[i][j]);
			if (!ft_strchr(" 01NSEW", game->map_comp[i][j]))
				return (allerrors(10));
			if (ft_strchr("NSEW", game->map_comp[i][j]))
			{
				if (hero > 0)
					return (allerrors(11));
				hero = 1;
				init_hero_pos(game, i, j);
			}
		}
	}
	return (EXIT_SUCCESS);
}

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
	if (check_chars(game))
		return (free_map_comp(game));
	return (EXIT_SUCCESS);
}
