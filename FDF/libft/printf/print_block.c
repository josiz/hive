/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:26:13 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/13 18:20:36 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int	print_block(char type, t_type *info, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = print_c(ap, info);
	if (type == 's')
		count = print_s(ap, info);
	if (type == 'p')
		count = print_p(ap, info);
	if (type == 'i' || type == 'd')
		count = print_i_d(ap, info);
	if (type == 'x' || type == 'X')
		count = print_x(ap, info, type);
	if (type == 'o')
		count = print_o(ap, info);
	if (type == 'u')
		count = print_u(ap, info);
	if (type == 'f')
		count = print_f(ap, info);
	if (type == '%')
		count = print_percent(info);
	if (type == 'b' || type == 'r' || type == 'k')
		return (0);
	return (count);
}

int	print_percent(t_type *info)
{
	int	ret_count;

	ret_count = 1;
	if (info->minus == 1)
		write(1, "%", 1);
	if (info->zero == 1 && info->minus == 0)
		putzero_count(info->width - 1, &ret_count);
	else
		putspaces_count(info->width - 1, &ret_count);
	if (info->minus == 0)
		write(1, "%", 1);
	return (ret_count);
}
