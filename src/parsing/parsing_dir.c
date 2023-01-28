/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:08:25 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/28 11:51:45 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Function to copy texture file names
static int	dir_utils(t_cub3d *game, char *line, int sign)
{
	int		len;
	char	*tmp;

	tmp = line;
	len = ft_strlen(line);
	if (len < 5)
		return (allerrors(7));
	tmp[len - 1] = '\0';
	if (ft_memcmp(".xpm", tmp + len - 5, 4) == 0)
		game->texture[sign].file_name = ft_strdup(line);
	else
		return (allerrors(7));
	if (game->texture[sign].file_name == NULL)
		return (allerrors(8));
	ft_printf("Copied direction textures: %s\n", game->texture[sign].file_name);
	return (0);
}

//Function to pars textures
int	parsing_dir(char *line, t_cub3d *game)
{
	int	sign;

	if (line[0] == 'N' && line[1] == 'O')
		sign = 0;
	else if (line[0] == 'S' && line[1] == 'O')
		sign = 1;
	else if (line[0] == 'E' && line[1] == 'A')
		sign = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		sign = 3;
	else
		return (allerrors(5));
	if (game->texture[sign].file_name != NULL)
		return (allerrors(6));
	if (line[2] != ' ')
		return (allerrors(7));
	line += 2;
	while (*line && *line == ' ')
		line++;
	return (dir_utils(game, line, sign));
}