/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:57 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/15 17:35:20 by zyunusov         ###   ########.fr       */
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
		// ft_printf("%s", *line);
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
	ft_printf("tmp = %d\n", game->map_h_tmp);
	if (calc_lines(game, map) < 3)
		return (EXIT_FAILURE);
	game->map_hght = game->map_hght - 1;
	ft_printf("%d\n", game->map_hght);
	game->map_comp = (char **)malloc(sizeof(char *) *game->map_hght);
	if (!game->map_comp)
		return(allerrors(9));
	i = -1;
	while (++i < (game->map_hght))
	{
		ft_printf("hght %d, %d\n", game->map_hght, i);
		game->map_comp[i] = malloc(1000);
		if (game->map_comp[i] == NULL)
			return (free_map_comp(game));
		// ft_printf("%s", line);
		ft_memcpy(game->map_comp[i], line, ft_strlen(line));
		game->map_comp[i][ft_strlen(line) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	print_map(game);
	return(0);
}