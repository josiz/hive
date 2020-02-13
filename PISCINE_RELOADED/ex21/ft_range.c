/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:46:04 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/16 11:44:50 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int a;
	int b;
	int *back;

	a = 0;
	b = min;
	if (min >= max)
		return (NULL);
	back = malloc(sizeof(int) * (max - min));
	while (b <= max)
	{
		back[a] = b;
		a++;
		b++;
	}
	return (back);
}
