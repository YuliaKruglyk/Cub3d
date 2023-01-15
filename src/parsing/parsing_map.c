/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:57 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/15 15:55:05 by zyunusov         ###   ########.fr       */
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
	// ft_printf("temporarly var = %s", tmp);
	*line = ft_strtrim(tmp, " ");
	free(tmp);
	while ((*line) != NULL)
	{
		ft_printf("%s", *line);
		if (**line == 'N' || **line =='S' || **line == 'E' || **line == 'W')
			res = 0;// parsing_direc(game, *line);
		else if (**line == 'C' || **line == 'F')
		 	res = 0;// parsing_colors(game, *line);
		else if (**line != '\0' && (**line == '1' || **line == ' '))
			return (0);
		free(*line);
		if (res)
			return (EXIT_FAILURE);
		*line = get_next_line(fd);
		game->map_h_tmp++;
	}
	if (*line == NULL)
		return (allerrors(4));
	return (0);
}

static int	calc_lines(t_cub3d *game, const char *map)
{
	int		res;
	int		fd;
	char	*tmp;

	res = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (allerrors(2));
	tmp = get_next_line(fd);
	while(tmp != NULL)
	{
		res++;
		free(tmp);
		tmp = get_next_line(fd);
		if (res > game->map_h_tmp && tmp != NULL)
			game->map_hght++;
	}
	close(fd);
	return (res);
}

// Function to start parsing the map
int	parsing_map(t_cub3d *game, const char *map, int fd)
{
	char	*line;

	if ((parsing_tex(game, fd, &line)))
		return (EXIT_FAILURE);
	if (calc_lines(game, map) < 3)
		return (EXIT_FAILURE);
	// ft_printf("%d", game->map_hght);
	return(0);
}