/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:24:32 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 15:40:26 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	*tempptr;

	tempptr = (char*)s;
	x = 0;
	while (1)
	{
		if (tempptr[x] == '\0' && c == '\0')
			return (&tempptr[x]);
		if (tempptr[x] == '\0')
			return (NULL);
		if (tempptr[x] == (char)c)
			return (&tempptr[x]);
		x++;
	}
	return (NULL);
}
