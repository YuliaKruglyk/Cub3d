/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:16:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/15 23:02:25 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

//Function to check if map surrounded by walls 
static int	border_utils(t_cub3d *game, int y, int x)
{
	if ((y == 0) || (y == game->map_hght - 1) || \
	(x == 0) || ((unsigned long)x == ft_strlen(game->map_comp[y]) - 1))
		return (EXIT_FAILURE);
	if ((game->map_comp[y - 1][x] == ' ') || \
	(game->map_comp[y + 1][x] == ' ') || \
	(game->map_comp[y][x - 1] == ' ') || (game->map_comp[y][x + 1] == ' '))
		return (EXIT_FAILURE);
	if (game->map_comp[y][x] == '0')
	{
		if ((game->map_comp[y - 1][0] == '\0') || \
		(game->map_comp[y + 1][0] == '\0'))
			return (EXIT_FAILURE);
		if ((game->map_comp[y - 1][x] == '\0') || \
		(game->map_comp[y + 1][x] == '\0'))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Function to check walls 
int	border_check(t_cub3d *game)
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
					return (allerrors2(12));
			}
			x++;
		}
	}
	return (EXIT_SUCCESS);
}

static void	view_point(t_cub3d *game, const char c)
{
	if (c == 'E')
		game->view = 0.0f * M_PI;
	else if (c == 'N')
		game->view = 0.5f * M_PI;
	else if (c == 'W')
		game->view = 1.0f * M_PI;
	else if (c == 'S')
		game->view = -0.5f * M_PI;
}

//Function that writes player position
static void	init_hero_pos(t_cub3d *game, int y, int x)
{
	game->player_x = (float)x + 0.5;
	game->player_y = (float)y + 0.5;
	view_point(game, game->map_comp[y][x]);
	return ;
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
