/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/06 14:56:53 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WINDOW_W		640
# define WINDOW_H		480
# define FOV			1.047f 
//The ratio between the length of the direction and the camera plane determinates the FOV
//FOV is 2 * atan(0.66/1.0)=66°

// ARROWS
#  define UP	126
#  define DOWN	125
#  define LEFT	123
#  define RIGHT	124
// KEYS
#  define KEY_W	13
#  define KEY_A	0
#  define KEY_S	1
#  define KEY_D	2
#  define K_ESC	53
#  define KEY_Q	12

typedef struct s_color
{
	int	r;
	int	g;
	int b;
}	t_color;

typedef struct s_image
{
	void	*img;
	char	*adrs;
	int		bits;
	int		line_len;
	int		b_order;
	int		width;
	int		height;
}	t_image;

typedef struct s_cub3d
{
	void		*mlx;
	int			map_h_tmp;
	int			map_hght;
	char		**map_comp;
	int			map_lnght;
	float		player_x;
	float		player_y;
	float		view;
	void		*window;
	t_color		color;
	int			ceil_col;
	int			floor_col;
	char		*file_name[4];
	int         txt_idx;
	float		txt_w;
	t_image		texture[4];
	t_image		image;
}	t_cub3d;

typedef struct s_raycast
{
	float	dx;
	float	dy;
	int		step_x;
	int		step_y;
	float	hor_x;
	float	map_y;
	float	map_x;
	float	vert_y;
	float	yside_dist;
	float	xside_dist;
	float	vert_w;
	float	hor_w;
}	t_raycast;

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
void	free_tex(t_cub3d *game);
// +++++++++++++++++++++++DEBUG++++++++++++++++++++++++++++++++++
void    print_map(t_cub3d *game);

void    init_image(t_cub3d *game);
void	build_window(t_cub3d *game);
void	raycasting(t_cub3d *game);
void	build_textures(t_cub3d *game, int width, float dest);
int	fromfloat(float f);
int ft_destroy_image(t_cub3d   *game);
int	keys(int kcode, t_cub3d *game);
float	ft_ray(t_cub3d *game, float view);

#endif