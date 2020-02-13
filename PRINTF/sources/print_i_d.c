/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:34:05 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 10:54:56 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	s_negative(t_type *info, long long *num, int *isneg)
{
	int ret;

	ret = 0;
	*isneg = *num < 0 ? 1 : 0;
	*num *= *num < 0 ? -1 : 1;
	if (!(num == 0 && info->dot == 1))
		ret = num_len(*num);
	ret += (*isneg == 1 || info->space == 1 || info->plus == 1) ? 1 : 0;
	return (ret);
}

static void	s_helper(t_type *info, long long num, int *ret)
{
	if (num == 0 && info->width > 0 &&
			info->dot == 1 && info->precision == 0 && info->minus == 0)
		putspaces_count(1, ret);
	if (num == 0 && info->width > 0 && info->dot == 1 && info->precision != 0)
		*ret += 1;
}

int			check_i_flags(long long num, t_type *info)
{
	int		ret;
	int		og_width;
	int		isneg;
	int		number_length;

	ret = s_negative(info, &num, &isneg);
	number_length = num_len(num);
	og_width = info->width;
	s_helper(info, num, &ret);
	if (info->minus == 1)
	{
		i_yes_minus2(info, isneg);
		put_plus_space(info, isneg);
		i_yes_minus(info, number_length, &ret, num);
	}
	if (info->minus == 0)
	{
		i_no_minus(info, number_length, isneg, &ret);
		if (!(num == 0 && info->dot == 1 && info->precision == 0))
			ft_putllnbr(num);
	}
	if ((info->dot == 1 && num == 0 && og_width != 0) ||
	(num == 0 && og_width == 0 && info->dot == 1 && info->precision == 0))
		ret--;
	return (ret);
}

int			print_i_d(va_list ap, t_type *info)
{
	int			length;
	long long	number;

	number = va_arg(ap, long long);
	length = 0;
	if (info->hh == 1)
		length += check_i_flags((char)number, info);
	else if (info->h == 1)
		length += check_i_flags((short)number, info);
	else if (info->ll == 1)
		length += check_i_flags((long long)number, info);
	else if (info->l == 1)
		length += check_i_flags((long)number, info);
	else
		length += check_i_flags((int)number, info);
	return (length);
}
