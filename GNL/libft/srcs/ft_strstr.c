/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:48:56 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 19:30:15 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0')
	{
		while (haystack[a + b] == needle[b])
		{
			if (needle[b] == '\0')
				return (&((char*)haystack)[a]);
			b++;
			if (needle[b] == '\0')
				return (&((char*)haystack)[a]);
		}
		b = 0;
		a++;
	}
	return (0);
}
