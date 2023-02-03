/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:41 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:15 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	allerrors(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nUsage: ./cub3d MAP.cub\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nCannot read the map\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nThe extension of map must be .cub\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMap is not exist\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nWrong textures format\nNeeds to be:\
		\nNO (SO, WE, EA) ./path_to_the_texture\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nTextures are duplicated\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nCannot load textures\nUnknown file's type\
		\nUse .xpm files as textures\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nCannot load textures\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nCannot allocate memory\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	return (1);
}

int allerrors2(int i)
{
	if (i == 11)
		ft_putstr_fd("Error\nMust be only one start position\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nThe map must be closed/surrounded by walls\n", 2);
	else if (i == 13)
		ft_putstr_fd("Error\nWrong floor or celling format\nRight format: \
		\nF 220,100,0 and C 225,30,0 where R,G,B - colors in range [0,255]\n", 2);
	else if (i == 14)
		ft_putstr_fd("Error\nTextures weren't set\nRight format:\
		\nNO (SO, WE, EA) ./path_to_the_texture\
		\nUse .xpm files as textures\n", 2);
	return (1);
}