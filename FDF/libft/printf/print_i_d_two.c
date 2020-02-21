/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:48:08 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 10:54:18 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		num_len(long long i)
{
	int ret;

	if (i == 0)
		return (1);
	ret = 0;
	while (i > 0)
	{
		i /= 10;
		ret++;
	}
	return (ret);
}

int		count_spaces_i(t_type *info, long long num, int isneg)
{
	int		len;
	int		number_length;

	len = isneg;
	len = 0;
	number_length = num_len(num);
	if (info->width >= number_length && info->width >= number_length)
		len = info->width;
	else if (info->precision >= info->width && info->precision >= number_length)
		len = info->precision;
	else
		len = number_length;
	len -= number_length;
	return (len);
}

void	i_no_minus(t_type *info, int number_length, int isneg, int *ret)
{
	info->width -= (isneg == 1 || info->space == 1 || info->plus == 1) ? 1 : 0;
	if (info->dot == 0 && info->zero == 1)
		put_plus_space(info, isneg);
	if (isneg == 1 && info->zero == 1 && info->dot == 0)
		write(1, "-", 1);
	if (info->dot == 0 && info->zero == 1)
		putzero_count(info->width -= info->precision >=
				number_length ? info->precision : number_length, ret);
	if (info->zero == 0 || (info->zero == 1 && info->dot == 1))
		putspaces_count(info->width -= info->precision >=
				number_length ? info->precision : number_length, ret);
	if (info->dot == 1 || (info->dot == 0 && (info->plus == 1 ||
					info->space == 1) && isneg == 0 && info->zero == 0))
		put_plus_space(info, isneg);
	if (isneg == 1 && info->zero == 0 && info->dot == 0)
		write(1, "-", 1);
	if (((isneg == 1 && info->zero == 0) ||
				(isneg == 1 && info->zero == 1)) && info->dot == 1)
		write(1, "-", 1);
	putzero_count(info->precision - number_length, ret);
}

void	i_yes_minus(t_type *info, int num_length, int *ret, long long num)
{
	if (num == 0 && info->width > 0 && info->dot == 1 && info->precision == 0)
		putspaces_count(1, ret);
	putzero_count(info->precision - num_length, ret);
	if (!(num == 0 && info->dot == 1 && info->precision == 0))
		ft_putllnbr(num);
	putspaces_count(info->width -= info->precision >=
			num_length ? info->precision : num_length, ret);
}

void	i_yes_minus2(t_type *info, int isneg)
{
	isneg == 1 ? write(1, "-", 1) : 0;
	info->width -= (isneg == 1 || info->space == 1 || info->plus == 1) ? 1 : 0;
}
