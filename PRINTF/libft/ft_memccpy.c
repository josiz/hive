/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:09:06 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 13:32:09 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	x = 0;
	while (x < n)
	{
		ptr1[x] = ptr2[x];
		if (ptr1[x] == (unsigned char)c)
			return ((void*)(dst + x + 1));
		x++;
	}
	return (NULL);
}
