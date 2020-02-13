/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_x_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:57:35 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 11:00:40 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void	print_x_0x(char type)
{
	if (type == 'x')
		write(1, "0x", 2);
	if (type == 'X')
		write(1, "0X", 2);
}

void	print_x_value(char type, long long num)
{
	if (type == 'x')
		ft_putstr(ft_itoa_base_lower(num, 16));
	if (type == 'X')
		ft_putstr(ft_itoa_base_upper(num, 16));
}

int		check_x_output_length(long long num, t_type *info)
{
	int	num_len;
	int	width_len;
	int	precision_len;

	if ((info->dot == 1 || info->width != 0) && num == 0)
		return (info->precision > info->width ? info->precision : info->width);
	if (num == 0)
		return (1);
	num_len = ft_strlen(ft_itoa_base_upper(num, 16));
	width_len = info->width;
	precision_len = info->precision;
	if (num_len >= width_len && num_len >= precision_len)
		return (num_len += info->hashtag == 1 ? 2 : 0);
	if (info->width == info->precision && info->hashtag == 1 && num != 0)
		width_len += 2;
	if (width_len >= num_len && width_len >= precision_len)
		return (width_len);
	else
		return (precision_len += info->hashtag == 1 ? 2 : 0);
}
