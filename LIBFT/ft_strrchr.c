/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:24:32 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 13:52:26 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*tempptr;

	tempptr = (char*)s;
	x = 0;
	while (s[x] != '\0')
		x++;
	while (x >= 0)
	{
		if (tempptr[x] == '\0' && c == '\0')
			return (&tempptr[x]);
		if (tempptr[x] == (char)c)
			return (&tempptr[x]);
		x--;
	}
	return (NULL);
}
