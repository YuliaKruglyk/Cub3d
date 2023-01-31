/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/31 09:24:08 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_color
{
	int	r;
	int	g;
	int b;
}	t_color;

typedef struct s_texture
{
	char	*file_name;
}	t_texture;

typedef struct s_cub3d
{
	void		*mlx;
	int			map_h_tmp;
	int			map_hght;
	char		**map_comp;
	int			map_lnght;
	float		player_x;
	float		player_y;
	t_texture	texture[4];
	t_color		color;
	int			ceil_col;
	int			floor_col;
}	t_cub3d;

//============================ERRORS============================
//Function to output err
int		allerrors(int i);
//Function to output err 2
int allerrors2(int i);
//==========================INITIALIZE==========================
//Function to initialize vars
void	init_game(t_cub3d *game);
//============================PARSING===========================
int		check_map_exten(const char *map);
// Function to start parsing the map
int		parsing_map(t_cub3d *game, const char *map, int fd);
//Function to read textures and parse
int	parsing_dir(char *line, t_cub3d *game);
//Function to count lenght of the each line of the map
int		ft_strlen1(char *s);
// Function that will go throww the map and check chars
int		check_map(t_cub3d *game);
//Function to parse rgb colors
int		parsing_colors(t_cub3d *game, char *line, char ch);
// =============================MEMORY FREE=====================
//Function for freeing while allocation failes
int		free_map_comp_err(t_cub3d *game);
//Function for freein in the end
void	free_map_comp2(t_cub3d *game);
// +++++++++++++++++++++++DEBUG++++++++++++++++++++++++++++++++++
void    print_map(t_cub3d *game);
#endif