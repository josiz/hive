/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:32:36 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 19:37:26 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	int		a;
	char	*back;

	a = 0;
	size = 0;
	while (src[size])
		size++;
	if (!(back = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[a])
	{
		back[a] = src[a];
		a++;
	}
	back[a] = '\0';
	return (back);
}
