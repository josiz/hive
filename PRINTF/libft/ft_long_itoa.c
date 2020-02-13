/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:01:04 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/12/16 15:24:13 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_length(long long n)
{
	int length;

	length = 0;
	if (n < 0)
		length++;
	if (n == 0)
		length = 1;
	while (n)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

static int	ifnegmax(long long c)
{
	if (c == -9223372036854775807)
	{
		return (1);
	}
	return (0);
}

char		*ft_long_itoa(long long n)
{
	char	*ptr;
	int		length;

	length = itoa_length(n);
	if (!(ptr = malloc(length + 1)))
		return (NULL);
	ptr[length] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		if (ifnegmax(n) == 1)
			return (ft_strdup("-9223372036854775807"));
		n = n * -1;
	}
	while ((n != 0 && length >= 0) && (n != -9223372036854775807))
	{
		ptr[length-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (ptr);
}
