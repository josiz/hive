/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:36:42 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/08 13:15:09 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		length1;
	int		length2;

	length1 = 0;
	length2 = 0;
	if (!(ptr = ((char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	while (s1[length2])
	{
		ptr[length2] = s1[length2];
		length2++;
	}
	while (s2[length1])
	{
		ptr[length2] = s2[length1];
		length2++;
		length1++;
	}
	ptr[length2] = '\0';
	return (ptr);
}
