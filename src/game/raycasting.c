/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:55:14 by ykruhlyk          #+#    #+#             */
/*   Updated: 2023/02/15 21:20:55 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_ray(t_cub3d *game, t_raycast *ray, float view)
{
	ray->dx = cos(view);
	ray->dy = -sin(view);
	ray->step_x = fromfloat(ray->dx);
	ray->step_y = fromfloat(ray->dy);
	ray->map_x = (int) game->player_x;
	if (ray->step_x > 0)
		ray->map_x += 1.0f;
	ray->map_y = (int) game->player_y;
	if (ray->step_y > 0)
		ray->map_y += 1.0f;
}

// xside_dist and yside_dist are initially the distance the ray has to travel 
// from its start position to the first x-side and the first y-side. 

//  If it has to go in the negative or positive x-direction, 
//  and the negative or positive y-direction
//  will depend on the direction of the ray, 
//  and this fact will be stored in stepX and stepY.
//  Those variables are always either -1 or +1.

static void	next_step_ray(t_cub3d *game, t_raycast *ray)
{
	if (ray->step_x != 0)
	{	
		ray->vert_y = game->player_y + ray->dy / \
			ray->dx * (ray->map_x - game->player_x);
		ray->yside_dist = sqrt(pow(game->player_x - ray->map_x, 2.0)
				+ pow(game->player_y - ray->vert_y, 2.0));
		ray->vert_w = ray->vert_y - (int) ray->vert_y;
		if (ray->step_x > 0)
			ray->vert_w = 1 - ray->vert_w;
	}
	else
		ray->yside_dist = INFINITY;
	if (ray->step_y != 0)
	{
		ray->hor_x = game->player_x + ray->dx / \
			ray->dy * (ray->map_y - game->player_y);
		ray->xside_dist = sqrt(pow(game->player_x - ray->hor_x, 2.0)
				+ pow(game->player_y - ray->map_y, 2.0));
		ray->hor_w = ray->hor_x - (int) ray->hor_x;
		if (ray->step_y < 0)
			ray->hor_w = 1 - ray->hor_w;
	}
	else
		ray->xside_dist = INFINITY;
}

static float	pixel_color(t_cub3d *game, float dist, int color_idx, float w)
{
	game->txt_idx = color_idx;
	game->txt_w = w;
	return (dist);
}

float	ft_ray(t_cub3d *game, float view)
{
	t_raycast	ray;

	init_ray(game, &ray, view);
	while (1)
	{
		next_step_ray(game, &ray);
		if (ray.yside_dist < ray.xside_dist)
		{
			if (game->map_comp[(int)ray.vert_y][(int)ray.map_x + \
				(ray.step_x - 1) / 2] == '1')
				return (pixel_color(game, ray.yside_dist, \
				ray.step_x + 1, ray.vert_w));
			else
				ray.map_x += ray.step_x;
		}
		else
		{
			if (game->map_comp[(int)ray.map_y + \
				(ray.step_y - 1) / 2][(int)ray.hor_x] == '1')
				return (pixel_color(game, ray.xside_dist, \
					ray.step_y + 2, ray.hor_w));
			else
				ray.map_y += ray.step_y;
		}
	}
}

void	raycasting(t_cub3d *game)
{
	int		x;
	float	dv;
	float	v;

	v = game->view - FOV / 2;
	dv = FOV / (WINDOW_W - 1);
	x = 0;
	while (x < WINDOW_W)
	{
		build_textures(game, x, ft_ray(game, v) * cos(game->view - v));
		v += dv;
		x++;
	}
}
