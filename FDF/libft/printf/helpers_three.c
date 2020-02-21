/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:08:46 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 11:08:57 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void	putzero_count(int i, int *count)
{
	while (i-- > 0)
	{
		write(1, "0", 1);
		*count += 1;
	}
}

void	putspaces(int i)
{
	while (i-- > 0)
	{
		write(1, " ", 1);
	}
}

void	putzero(int i)
{
	while (i-- > 0)
	{
		write(1, "0", 1);
	}
}

char	*ft_itoa_base_upper(long long num, int base)
{
	unsigned long long	value;
	static char			signs[] = "0123456789ABCDEF";
	static char			ret[50];
	char				*ptr;

	value = (unsigned long long)num;
	ptr = &ret[49];
	*ptr = '\0';
	ptr--;
	if (value == 0)
	{
		*ptr = signs[0];
		return (ptr);
	}
	while (value > 0)
	{
		*ptr = signs[value % base];
		value = value / base;
		ptr--;
	}
	ptr++;
	return (ptr);
}

char	*ft_itoa_base_lower(long long num, int base)
{
	unsigned long long	value;
	static char			signs[] = "0123456789abcdef";
	static char			ret[50];
	char				*ptr;

	value = (unsigned long long)num;
	ptr = &ret[49];
	*ptr = '\0';
	ptr--;
	if (value == 0)
	{
		*ptr = signs[0];
		return (ptr);
	}
	while (value > 0)
	{
		*ptr = signs[value % base];
		value = value / base;
		ptr--;
	}
	ptr++;
	return (ptr);
}
