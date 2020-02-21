/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:17:37 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:49:39 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

static void	x_no_minus2(t_type *info, int og_w, long long num, char type)
{
	int	print_amount;
	int	number_len;

	number_len = ft_strlen(ft_itoa_base_upper(num, 16));
	if (num == 0)
		number_len = 0;
	print_amount = info->precision - number_len;
	if ((info->hashtag == 1 && num != 0 && info->zero == 0) ||
			(number_len < og_w &&
			info->hashtag == 1 && num != 0 && og_w != 0 && info->dot == 1))
		print_x_0x(type);
	if (num == 0 && info->dot == 1 && info->precision == 0 && info->zero == 0)
		print_amount = info->width;
	if (info->zero == 1 || (num == 0 && info->precision != 0 && info->dot == 1)
			|| (info->precision > info->width) || info->precision > number_len)
		putzero(print_amount);
	if (!(info->dot == 1 && num == 0))
		print_x_value(type, num);
}

static void	x_no_minus(t_type *info, char type, int og_w, long long num)
{
	int	number_len;
	int	print_amount;

	number_len = ft_strlen(ft_itoa_base_upper(num, 16));
	if (num == 0)
		number_len = 0;
	print_amount = info->width -= (info->precision >= number_len ?
			info->precision : number_len);
	if (info->hashtag == 1 && num != 0)
		print_amount -= 2;
	if ((info->hashtag == 1 && num != 0 && info->zero == 1 &&
				(og_w <= number_len)) || (info->zero == 1 && info->dot == 0 &&
					og_w > number_len && info->hashtag == 1 && num != 0))
		print_x_0x(type);
	if (num == 0 && info->dot == 1 && og_w < info->precision)
		print_amount++;
	if (num == 0 && info->width != 0 && info->dot == 0)
		print_amount--;
	if ((info->zero == 1 && info->dot == 0) || (og_w < info->precision))
		putzero(print_amount);
	else
		putspaces(print_amount);
	x_no_minus2(info, og_w, num, type);
}

static void	x_yes_minus(t_type *info, char type, int og_width, long long num)
{
	int	number_len;
	int	print_amount;

	number_len = ft_strlen(ft_itoa_base_upper(num, 16));
	if (num == 0)
		number_len = 0;
	if (info->hashtag == 1 && num != 0)
		print_x_0x(type);
	print_amount = info->precision - number_len;
	while (print_amount-- > 0)
		write(1, "0", 1);
	if (!(info->dot == 1 && num == 0))
		print_x_value(type, num);
	print_amount = info->width -= (info->precision >= number_len ?
			info->precision : number_len);
	if (info->hashtag == 1 && num != 0)
		print_amount -= 2;
	if (num == 0 && info->dot == 1 && og_width < info->precision)
		print_amount++;
	if (num == 0 && info->width != 0 && info->dot == 0)
		print_amount--;
	while (print_amount-- > 0)
		write(1, " ", 1);
}

static int	check_x_flags(long long num, t_type *info, char type)
{
	int	output_len;
	int	number_len;
	int	og_width;

	number_len = ft_strlen(ft_itoa_base_upper(num, 16));
	output_len = check_x_output_length(num, info);
	og_width = info->width;
	if (num == 0)
		number_len = 0;
	if (info->minus == 1)
		x_yes_minus(info, type, og_width, num);
	if (info->minus == 0)
		x_no_minus(info, type, og_width, num);
	if (info->hashtag == 1 && num != 0 && og_width == info->precision + 1)
		output_len++;
	return (output_len);
}

int			print_x(va_list ap, t_type *info, char a)
{
	int					length;
	unsigned long long	number;

	number = va_arg(ap, unsigned long long);
	length = 0;
	if (info->hh == 1)
		length += check_x_flags((unsigned char)number, info, a);
	else if (info->h == 1)
		length += check_x_flags((unsigned short)number, info, a);
	else if (info->ll == 1)
		length += check_x_flags((unsigned long long)number, info, a);
	else if (info->l == 1)
		length += check_x_flags((unsigned long)number, info, a);
	else
		length += check_x_flags((unsigned int)number, info, a);
	return (length);
}
