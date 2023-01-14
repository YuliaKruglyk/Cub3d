/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_direc_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:21:27 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/14 12:54:50 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	parsing_direc_utils(t_cub3d *game, cahr *line,int s)
{
	char	*tmp;
	int		len;

	tmp = line;
	len = ft_strlen(line);
	if (len < 5)
		return (allerrors(7));
	tmp[len - 1] = '\0';
	if (ft_memcmp(".xpm", tmp + len - 5, 4) == 0)
		game->texture[s].ptr = mlx_xpm_file_to_image(game->mlx, line, \
		(int *)&game->texture[s].width, (int *)&game->texture[s].height);
	else
		return (allerrors(7));
	if (game->texture[s].ptr == NULL)
		return (allerrors(8));
	return (0);
}

int	parsing_direc(t_cub3d *game, char *line)
{
	int	s;

	if (line[0] == 'N' && line[1] == 'O')
		s = 0;
	else if (line[0] == 'S' && line[1] == 'O')
		s = 1;
	else if (line[0] == 'E' && line[1] == 'A')
		s = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		s = 3;
	else
		return (allerrors(5));
	if (game->texture[s]. ptr != NULL)
		return (allerrors(6));
	if (line[2] != ' ')
		return (allerrors(5));
	line += 2;
	while (*line && *line == ' ')
		line++;
	return (parsing_direc_utils(game, line, s));
}