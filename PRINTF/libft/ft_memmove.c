/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:47 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 16:13:36 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr2 = (char *)src;
	ptr1 = (char *)dst;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			ptr1[i] = ptr2[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}
