/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:57 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/13 14:13:21 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Function to get_map and pars textures
static int	parsing_tex(t_cub3d *game, int fd, char **line)
{
	int		res;
	char	*tmp;

	res = 0;
	tmp = get_next_line(fd);
	ft_printf("temporarly var = %s", tmp);
	*line = ft_strtrim(tmp, " ");
	ft_printf("Line = %s", line);
	free(tmp);
	while ((*line) != NULL)
	{
		if (**line == 'N' || **line =='S' || **line == 'E' || **line == 'W')
			res = parsing_direc(game, *line);
		else
			return (0);
		free(*line);
		if (res)
			return (EXIT_FAILURE);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		return (allerrors(4));
	return (0);
}

// Function to start parsing the map
int	parsing_map(t_cub3d *game, const char *map, int fd)
{
	char	*line;
	
	if ((parsing_tex(game, fd, &line)))
		return (EXIT_FAILURE);
	
}