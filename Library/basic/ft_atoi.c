/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:19:51 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:16:31 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	a;
	int			p;
	int			isnegative;

	a = 0;
	isnegative = 1;
	p = 0;
	while (ft_isspace(str[p]) == 1)
		p++;
	if (str[p] == '-' || str[p] == '+')
	{
		if (str[p] == '-')
			isnegative = -1;
		p++;
	}
	while (str[p] != '\0' && str[p] >= '0' && str[p] <= '9')
	{
		a = a * 10 + (str[p] - '0');
		p++;
	}
	a = a * isnegative;
	return (a);
}
