/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:34:36 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/25 19:10:28 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		count1;
	int		count2;
	size_t	x;

	count1 = 0;
	count2 = 0;
	x = 0;
	while (s1[count1])
		count1++;
	while (s2[count2] != '\0' && x < n)
	{
		s1[count1] = s2[count2];
		count1++;
		count2++;
		x++;
	}
	s1[count1] = '\0';
	return (s1);
}
