/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:15:31 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/28 12:38:59 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*tempptr;

	tempptr = (unsigned char*)b;
	a = 0;
	while (a < len)
	{
		tempptr[a] = (unsigned char)c;
		a++;
	}
	return (tempptr);
}
