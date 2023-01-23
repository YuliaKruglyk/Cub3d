/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:34:57 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/23 14:55:13 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    print_map(t_cub3d *game)
{
    int i;

    i = 0;
    while(game->map_comp[i])
    {
        ft_printf("%s", game->map_comp[i]);
        i++;
    }
}