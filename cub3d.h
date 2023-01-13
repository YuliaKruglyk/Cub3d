/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/13 14:11:59 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <fcntl.h>

typedef struct s_texture
{
	void	*ptr;
}	t_texture;

typedef struct s_cub3d
{
	char		**map_comp;
	t_texture	texture[4];	
}	t_cub3d;

//============================ERRORS============================
int	allerrors(int i);
//============================PARSING============================
int	check_map_exten(const char *map);
// Function to start parsing the map
int	parsing_map(t_cub3d *game, const cahr *map, int fd)

#endif