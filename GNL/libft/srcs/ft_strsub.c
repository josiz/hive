/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:11:31 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/29 17:21:47 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s || !(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i + start];
		i += 1;
	}
	sub[i] = '\0';
	return (sub);
}
