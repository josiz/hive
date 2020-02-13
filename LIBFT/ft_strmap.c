/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:36:43 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/23 16:47:50 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	char	*ptr;
	char	*src;

	src = (char*)s;
	a = 0;
	while (s[a])
		a++;
	if (!(ptr = malloc(a + 1)))
		return (NULL);
	a = 0;
	while (src[a])
	{
		ptr[a] = f(src[a]);
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
