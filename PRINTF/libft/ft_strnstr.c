/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:48:56 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 14:35:48 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	i;

	if (!*needle)
		return ((char*)haystack);
	x = 0;
	while (haystack[x] != '\0' && x < len)
	{
		if (haystack[x] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[x + i] == needle[i] &&
					(x + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[x]);
		}
		x++;
	}
	return (0);
}
