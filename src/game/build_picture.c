/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_picture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:49:09 by ykruhlyk          #+#    #+#             */
/*   Updated: 2023/02/15 21:28:35 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	build_floor_and_celling(t_cub3d *game)
{
	unsigned int	*pix;
	unsigned int	i;

	pix = (unsigned int *) game->image.adrs;
	i = WINDOW_W * WINDOW_H / 2;
	while (i > 0)
	{
		*pix = game->ceil_col;
		pix++;
		i--;
	}
	i = WINDOW_W * WINDOW_H / 2;
	while (i > 0)
	{
		*pix = game->floor_col;
		pix++;
		i--;
	}
}

void	build_textures(t_cub3d *game, int width, float dest)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) WINDOW_H / dest;
	src_f = 0.0f;
	d_shift = (float) game->texture[game->txt_idx].height / h;
	if (h > WINDOW_H)
	{
		src_f = 0.5f * (h - WINDOW_H) / h * game->texture[game->txt_idx].height;
		h = WINDOW_H;
	}
	src = (unsigned int *) game->texture[game->txt_idx].adrs;
	src += (int)((float) game->txt_w * game->texture[game->txt_idx].width);
	dst = (unsigned int *) game->image.adrs + \
		width + (WINDOW_H - h) / 2 * WINDOW_W;
	while (h > 0)
	{
		*dst = *(src + ((int)src_f) * game->texture[game->txt_idx].width);
		dst += WINDOW_W;
		src_f += d_shift;
		h--;
	}
}

void	build_window(t_cub3d *game)
{
	game->image.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	game->image.adrs = mlx_get_data_addr(game->image.img, &game->image.bits,
			&game->image.line_len, &game->image.b_order);
	build_floor_and_celling(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);
	mlx_destroy_image(game->mlx, game->image.img);
}
