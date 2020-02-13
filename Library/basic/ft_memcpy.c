/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:22:48 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 14:08:43 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	x = 0;
	if (dst == src || !n)
		return (ptr1);
	while (x < n)
	{
		ptr1[x] = ptr2[x];
		x++;
	}
	return (ptr1);
}
