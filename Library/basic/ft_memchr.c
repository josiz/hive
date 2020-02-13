/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:50:34 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/24 16:53:03 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*ptr;

	x = 0;
	ptr = (unsigned char*)s;
	while (x < n)
	{
		if (ptr[x] == (unsigned char)c)
			return (ptr + x);
		x++;
	}
	return (NULL);
}
