/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:49:07 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 18:10:44 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void		putfloat(long double ognum, t_type *info, char *decimal)
{
	long double			num;
	int					negative;
	long long			number;

	num = (ognum < 0) ? -ognum : ognum;
	negative = (ognum < 0) ? -1 : 1;
	number = (unsigned long long)num;
	if (round_decimal(decimal, info) == 1)
		number += 1;
	num -= number;
	ft_putllnbr(number);
	if (info->precision > 0 || info->hashtag == 1)
		ft_putchar('.');
	ft_putnstr(decimal, info->precision);
	free(decimal);
}

static int	count_spaces(int count, t_type *info, char *a, int isneg)
{
	int		len;

	*a = (info->zero == 1 && (info->precision == 6 &&
				info->minus == 0)) ? '0' : ' ';
	len = count + ((isneg == 1 || info->space == 1 || info->plus == 1) ? 1 : 0);
	if (info->dot == 0 && (info->width < len + 7))
		len -= 1;
	return ((info->width > len) ? info->width - len : 0);
}

static void	check_two(t_type *info, int spaces, int *ret_c, long double num)
{
	if (info->precision == 0 && info->dot == 0)
		info->precision = 6;
	if (info->minus == 0 && info->zero == 0)
		putspaces_count(spaces, ret_c);
	if (num >= 0 && info->space == 1 && info->plus == 0)
	{
		ft_putchar(' ');
		*ret_c += 1;
	}
}

int			check_f_flags(long double num, t_type *info)
{
	int		ret_count;
	char	a;
	int		isneg;
	int		spaces;
	char	*decimal;

	decimal = get_decimal(num, info);
	isneg = (num < 0) ? 1 : 0;
	spaces = 0;
	ret_count = 0;
	ret_count += count_f_length(num, info, decimal, &spaces);
	num += info->roundup == 1 ? 1 : 0;
	free(decimal);
	decimal = get_decimal(num, info);
	spaces += count_spaces(ret_count, info, &a, isneg);
	spaces -= (info->precision == 0 && info->dot == 0) ? 7 : 0;
	check_two(info, spaces, &ret_count, num);
	put_sign(num, &ret_count, info);
	if (info->minus == 0 && info->zero == 1)
		putzero_count(spaces, &ret_count);
	putfloat(num, info, decimal);
	check_f_helper(info, spaces, &ret_count);
	ret_count += (info->dot == 0 && info->hashtag == 1) ? 6 : 0;
	ret_count += (info->dot == 0 && info->hashtag == 0) ? 7 : 0;
	return (ret_count);
}

int			print_f(va_list ap, t_type *info)
{
	int			length;
	long double	number;

	length = 0;
	if (info->bigl == 1)
	{
		number = va_arg(ap, long double);
		length += check_f_flags((long double)number, info);
	}
	else if (info->l == 1)
	{
		number = va_arg(ap, double);
		length += check_f_flags((double)number, info);
	}
	else
	{
		number = va_arg(ap, double);
		length += check_f_flags((double)number, info);
	}
	return (length);
}
