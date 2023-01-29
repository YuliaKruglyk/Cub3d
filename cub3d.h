/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/29 12:49:51 by zyunusov         ###   ########.fr       */
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
int	parsing_dir(char *line, t_cub3d *game);
//Function to count lenght of the each line of the map
int		ft_strlen1(char *s);
// Function that will go throww the map and check chars
int		check_map(t_cub3d *game);

// =============================MEMORY FREE=====================
//Function for freeing while allocation failes
int		free_map_comp_err(t_cub3d *game);
//Function for freein in the end
void	free_map_comp2(t_cub3d *game);
// +++++++++++++++++++++++DEBUG++++++++++++++++++++++++++++++++++
void    print_map(t_cub3d *game);
#endif