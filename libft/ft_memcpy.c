/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:03:32 by zyunusov          #+#    #+#             */
/*   Updated: 2023/01/24 10:46:44 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;

	if (dest == src)
		return (dest);
	c = (unsigned char *)src;
	p = (unsigned char *)dest;
	while (n--)
		*p++ = *c++;
	return (dest);
}
