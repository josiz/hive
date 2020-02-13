/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:09:49 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 13:47:11 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len && src[a])
	{
		dst[a] = src[a];
		a++;
	}
	if (src[a] == '\0')
		dst[a] = '\0';
	while (a < len)
	{
		dst[a] = '\0';
		a++;
	}
	return (dst);
}
