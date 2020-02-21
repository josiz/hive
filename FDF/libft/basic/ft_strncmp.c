/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:40:50 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 14:41:21 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0' && a < n - 1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
