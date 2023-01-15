/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:41 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/15 16:24:51 by zyunusov         ###   ########.fr       */
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
	return (1);
}
