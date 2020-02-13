/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:08:32 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 11:34:42 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	x = 0;
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (ptr1[x] == '\0' || ptr2[x] == '\0')
		return (ptr1[x] - ptr2[x]);
	if (n == 0)
		return (0);
	while (x < n)
	{
		if (ptr1[x] != ptr2[x])
			return (ptr1[x] - ptr2[x]);
		if (n == x + 1)
			return (ptr1[x] - ptr2[x]);
		x++;
	}
	return (0);
}
