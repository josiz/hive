/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:08:25 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:13:28 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*double_itoa(long double num, int len)
{
	long double	a;
	char		*ptr;
	int			i;
	long		number;

	a = num;
	i = 0;
	if (!(ptr = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		a *= 10;
		number = (long)a;
		ptr[i] = number + '0';
		a = a - (long)a;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	put_plus_space(t_type *info, int isneg)
{
	if (info->space == 1 && info->plus == 1 && isneg == 0)
	{
		write(1, "+", 1);
		return ;
	}
	if (info->plus == 1 && isneg == 0)
	{
		write(1, "+", 1);
		return ;
	}
	if (info->space == 1 && isneg == 0)
		write(1, " ", 1);
	return ;
}

char	*declare_null(void)
{
	char *s;

	s = malloc(7);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = '\0';
	return (s);
}

char	*ft_itoa_base_test(long long num, int base)
{
	unsigned long long	value;
	static char			signs[] = "0123456789abcdef";
	static char			ret[50];
	char				*ptr;

	if (ft_itoa_base_test_two(num) == 1)
		return (0);
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
	ft_putstr(ptr);
	return (ptr);
}

void	o_no_minus2(t_type *info, long long num, char *octa, int octa_len)
{
	if ((info->hashtag == 1 && num != 0) || (info->hashtag == 1 && num == 0
				&& info->dot == 1 && info->precision == 0))
		write(1, "0", 1);
	info->precision > octa_len ? putzero(info->precision - octa_len) : 0;
	if (!(info->dot == 1 && num == 0))
		octa = ft_itoa_base_test(num, 8);
}
