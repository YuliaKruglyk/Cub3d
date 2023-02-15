/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:46:28 by ykruhlyk          #+#    #+#             */
/*   Updated: 2023/02/15 21:20:52 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_func(t_cub3d *game, int direct)
{
	float	dist;
	float	dist_x;
	float	dist_y;
	float	ang;

	ang = game->view + direct * M_PI / 2;
	dist_x = 0.3f * cos(ang);
	dist_y = 0.3f * sin(ang);
	dist = ft_ray(game, fromfloat(dist_y) * M_PI / 2);
	if (dist * dist < dist_y * dist_y)
		dist_y = 0.0f;
	dist = ft_ray(game, (1 - (fromfloat(dist_x) + 1) / 2) * M_PI);
	if (dist * dist < dist_x * dist_x)
		dist_x = 0.0f;
	dist = ft_ray(game, ang);
	if (dist * dist < dist_y * dist_y + dist_x * dist_x)
		if (fromfloat(dist_y) * fromfloat(dist_x) != 0)
			dist_y = 0.0f;
	game->player_x = game->player_x + dist_x;
	game->player_y = game->player_y - dist_y;
}

int	keys(int kcode, t_cub3d *game)
{
	if (kcode == K_ESC)
		ft_destroy_image(game);
	else if (kcode == UP || kcode == KEY_W)
		move_func(game, 0);
	else if (kcode == DOWN || kcode == KEY_S)
		move_func(game, 2);
	else if (kcode == LEFT)
		game->view -= 0.02f * M_PI;
	else if (kcode == RIGHT)
		game->view += 0.02f * M_PI;
	else if (kcode == KEY_A)
		move_func(game, 3);
	else if (kcode == KEY_D)
		move_func(game, 1);
	else
		return (0);
	build_window(game);
	return (0);
}
