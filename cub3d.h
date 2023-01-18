/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/18 14:00:41 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_texture
{
	void			*ptr;
	unsigned int	width;
	unsigned int	height;
}	t_texture;

typedef struct s_cub3d
{
	void		*mlx;
	t_texture	texture[4];
	int			map_h_tmp;
	int			map_hght;
	char		**map_comp;
	int			map_lnght;
	int			player_x;
	int			player_y;
}	t_cub3d;

//============================ERRORS============================
int		allerrors(int i);
//==========================INITIALIZE==========================
void	init_game(t_cub3d *game);
//============================PARSING===========================
int		check_map_exten(const char *map);
// Function to start parsing the map
int		parsing_map(t_cub3d *game, const char *map, int fd);
//Function to read textures and parse
// int		parsing_direc(t_cub3d *game, char *line);
//Function to count lenght of the each line of the map
int		ft_strlen1(char *s);
// Function that will go throww the map and check chars
int	check_map(t_cub3d *game);

// =============================MEMORY FREE=====================
int		free_map_comp(t_cub3d *game);

// +++++++++++++++++++++++DEBUG++++++++++++++++++++++++++++++++++
void    print_map(t_cub3d *game);
#endif