/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:39:52 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 11:07:53 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*get_decimal(long double num, t_type *info)
{
	int			count;
	long double	ret;
	char		*back;

	ret = num;
	ret *= ret < 0 ? -1 : 1;
	ret = ret - (unsigned long long)ret;
	if (info->precision == 0)
		count = 7;
	else
		count = info->precision + 1;
	back = double_itoa(ret, count);
	return (back);
}

static void	round2(char *decimal, int *index)
{
	if (decimal[*index] == ':' && *index != 0)
	{
		decimal[*index] = '0';
		decimal[*index - 1]++;
	}
	*index -= 1;
}

int			round_decimal(char *decimal, t_type *info)
{
	int	index;
	int	first_is_over;

	first_is_over = 0;
	if (info->precision == 0 && info->dot == 1)
		index = 0;
	else if (info->precision == 0)
		index = 6;
	else
		index = info->precision;
	if (decimal[index] >= '5')
	{
		if (index == 0)
			return (1);
		decimal[index - 1]++;
	}
	while (index >= 0)
		round2(decimal, &index);
	if (decimal[0] == ':')
	{
		first_is_over = 1;
		while (index++ < info->precision)
			decimal[index] = '0';
	}
	return (first_is_over);
}

int			count_f_length(long double num, t_type *info, char *dec, int *sp)
{
	unsigned long long	number1;
	unsigned long long	number2;
	int					length;
	int					isneg;

	isneg = 0;
	length = 0;
	num *= num < 0 ? -1 : 1;
	number1 = (unsigned long long)num;
	length += num_len(number1);
	length += (info->precision > 0 || info->hashtag == 1) ? 1 : 0;
	length += info->precision;
	number2 = number1;
	if (round_decimal(dec, info) == 1)
	{
		number2++;
	}
	if (num_len(number1) != num_len(number2))
	{
		length++;
		*sp -= 0;
	}
	return (length);
}

void		put_sign(long double num, int *count, t_type *info)
{
	if (info->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
	}
	if (num < 0)
	{
		ft_putchar('-');
		*count += 1;
	}
}
