/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:10:56 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/07 18:03:42 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Function to convert str to number for only red and green
static int	parsing_cnum(char **line)
{
	int		i;
	char	str[4];

	while (**line == ' ')
		(*line)++;
	i = 0;
	while ((**line) && (**line) != ',' && (**line) != ' ')
	{
		if (ft_isdigit(**line))
			str[i] = **line;
		else
			break ;
		(*line)++;
		i++;
	}
	while (**line && **line == ' ')
		(*line)++;
	if (**line != ',' || i > 3)
		return (-1);
	str[i] = '\0';
	i = ft_atoi(str);
	if (i > 255)
		return (-1);
	(*line)++;
	return (i);
}

//Function to convert str to number for only black
static int	parsing_cnum_2(char **line)
{
	int		i;
	char	str[4];

	while (**line == ' ')
		(*line)++;
	i = 0;
	while ((**line) && (**line) != ' ')
	{
		if (ft_isdigit(**line))
			str[i] = **line;
		else
			break ;
		(*line)++;
		i++;
	}
	while (**line == ' ')
		(*line)++;
	if (**line != '\0' && **line != 10)
		return (-1);
	str[i] = '\0';
	i = ft_atoi(str);
	if (i > 255)
		return (-1);
	(*line)++;
	return (i);
}

static void	parsing_f_c(t_cub3d *game, char ch)
{
	if (ch == 'F')
		game->floor_col = (game->color.r << 16) | (game->color.g << 8) | \
		game->color.b;
	else
		game->ceil_col = (game->color.r << 16) | (game->color.g << 8) | \
		game->color.b;
}

//Function to parse colors
int	parsing_colors(t_cub3d *game, char *line, char ch)
{
	int	res;

	if ((ch == 'C' || ch == 'F'))
		line++;
	if (*line != ' ')
		return (allerrors2(13));
	res = parsing_cnum(&line);
	if (res < 0)
		return (allerrors2(13));
	game->color.r = res;
	ft_printf("Red: %d\n", game->color.r);
	res = parsing_cnum(&line);
	if (res < 0)
		return (allerrors2(13));
	game->color.g = res;
	ft_printf("Green: %d\n", game->color.g);
	res = parsing_cnum_2(&line);
	if (res < 0)
		return (allerrors(13));
	game->color.b = res;
	ft_printf("Black: %d\n", game->color.b);
	parsing_f_c(game, ch);
	return (EXIT_SUCCESS);
}
