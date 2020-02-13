/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:04:36 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 19:11:24 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = 0;
	z = 0;
	while (dst[x] != '\0')
		++x;
	while (src[y] != '\0')
		++y;
	if (dstsize <= x)
		y = y + dstsize;
	else
		y = y + x;
	while (src[z] != '\0' && x + 1 < dstsize)
	{
		dst[x] = src[z];
		x++;
		z++;
	}
	dst[x] = '\0';
	return (y);
}
