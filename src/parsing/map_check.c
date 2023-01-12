/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:16:09 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/12 13:34:55 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map_exten(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		return (allerrors(2));
	return (0);
}