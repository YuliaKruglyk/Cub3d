/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:38 by zyunusov          #+#    #+#             */
/*   Updated: 2023/02/07 18:01:16 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	return (i);
}

int	fromfloat(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}
