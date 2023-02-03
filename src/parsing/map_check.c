/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:16:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/03 14:11:56 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

//Function to check if map surrounded by walls 
static int border_utils(t_cub3d *game, int y, int x)
{
	if ((y == 0) || (y == game->map_hght - 1) || \
	(x == 0) || ((unsigned long)x == ft_strlen(game->map_comp[y]) - 1))
		return (EXIT_FAILURE);
	if ((game->map_comp[y - 1][x] == ' ') || (game->map_comp[y + 1][x] == ' ') || \
	(game->map_comp[y][x - 1] == ' ') || (game->map_comp[y][x + 1] == ' '))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//Function to check walls 
static int border_check(t_cub3d *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_hght)
	{
		x = 0;
		while (game->map_comp[y][x])
		{
			if (ft_strchr("0NSWE", game->map_comp[y][x]))
			{
				if (border_utils(game, y, x))
					return (allerrors(12));
			}
			x++;
		}
	}
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

//Function that writes player position
static void	init_hero_pos(t_cub3d *game, int y, int x)
{
	game->player_x = (float)x;
	game->player_y = (float)y;
	ft_printf("\nPLAYER: %c\n", game->map_comp[y][x]);
	printf("player x : %f, player y : %f\n", game->player_x, game->player_y);
}

//Function to check any invalid chars for the map and detect hero pos
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
