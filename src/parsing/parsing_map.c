/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:57 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/03 13:42:32 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

//Function to get_map and pars textures
static int	parsing_tex(t_cub3d *game, int fd, char **line)
{
	int		res;
	char	*tmp;

	res = 0;
	tmp = get_next_line(fd);
	*line = ft_strtrim(tmp, " ");
	free(tmp);
	while ((*line) != NULL)
	{
		if (**line == 'N' || **line =='S' || **line == 'E' || **line == 'W')
			res = parsing_dir(*line, game);
		else if (**line == 'C' || **line == 'F')
		 	res = parsing_colors(game, *line, **line);
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

//Function to calculate height of the map
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
	while (tmp != NULL)
	{
		res++;
		free(tmp);
		tmp = get_next_line(fd);
		if (res > game->map_h_tmp && tmp != (void *) 0)
			game->map_hght++;
	}
	close(fd);
	return (res);
}

// Function to start parsing the map
int	parsing_map(t_cub3d *game, const char *map, int fd)
{
	char	*line;
	int		i;

	if ((parsing_tex(game, fd, &line)))
		return (EXIT_FAILURE);
	// ft_printf("tmp = %d\n", game->map_h_tmp);
	if (calc_lines(game, map) < 3)
		return (EXIT_FAILURE);
	// ft_printf("%d\n", game->map_hght);
	game->map_comp = (char **)malloc(sizeof(char *) * game->map_hght);
	if (!game->map_comp)
		return(allerrors(9));
	i = -1;
	while (++i < (game->map_hght))
	{
		// printf("hght %d, %d\n", game->map_hght, i);
		game->map_comp[i] = malloc(1000);
		if (game->map_comp[i] == NULL)
			return (free_map_comp_err(game));
		ft_printf("%s", line);
		ft_memcpy(game->map_comp[i], line, ft_strlen(line));
		game->map_comp[i][ft_strlen(line) - 1] = '\0';
		free(line);
		// ft_printf("HERE!\n");
		line = get_next_line(fd);
		// ft_printf("HERE!1\n");
	}
	// print_map(game);
	return (check_map(game));
}
