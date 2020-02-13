/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:19:32 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:14:32 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

static int	check_output_length(long long num, t_type *info)
{
	int numb_len;
	int width_len;
	int precision_len;

	numb_len = ft_strlen(ft_itoa_base_lower(num, 10));
	width_len = info->width;
	precision_len = info->precision;
	if (num == 0 && info->dot == 1 && info->width == 0)
		return (0);
	if (numb_len >= width_len && numb_len >= precision_len)
		return (numb_len);
	if (width_len >= numb_len && width_len >= precision_len)
		return (width_len);
	else
		return (precision_len);
}

static void	u_yes_minus(t_type *info, long long num, int octa_len, char *octa)
{
	info->hashtag == 1 ? (info->precision--) : 0;
	info->precision > octa_len ? putzero(info->precision - octa_len) : 0;
	info->hashtag == 1 ? write(1, "0", 1) : 0;
	(info->hashtag == 1 && info->width > info->precision) ? info->width-- : 0;
	if (num == 0 && info->width > 0 && info->dot == 1 && info->precision == 0)
		putspaces(1);
	if (!(num == 0 && info->dot == 1 && info->precision == 0))
		ft_putstr(octa);
	if (info->width > info->precision || info->width > octa_len)
		info->precision > octa_len ?
			putspaces(info->width - info->precision) :
			putspaces(info->width - octa_len);
}

static void	u_no_minus(t_type *info, long long num, int octa_len, char *octa)
{
	info->hashtag == 1 ? (info->width--) : 0;
	info->hashtag == 1 ? (info->precision--) : 0;
	if (num == 0 && info->width > 0 && info->dot == 1 && info->precision == 0)
		putspaces(1);
	if (info->zero == 1 && (info->width > octa_len) && info->dot == 0)
		putzero(info->width - octa_len);
	else if ((info->width > info->precision || info->width > octa_len) &&
			(info->zero == 0 || info->precision == 0))
		info->precision > octa_len ? putspaces(info->width - info->precision) :
			putspaces(info->width - octa_len);
	else if (info->zero == 1 && info->precision != 0)
		info->precision > octa_len ? putspaces(info->width - info->precision) :
			putspaces(info->width - octa_len);
	else if ((info->width > info->precision || info->width > octa_len) &&
			info->zero == 1)
		info->precision > octa_len ? putzero(info->width - info->precision) :
			putzero(info->width - octa_len);
	info->hashtag == 1 ? write(1, "0", 1) : 0;
	info->precision > octa_len ? putzero(info->precision - octa_len) : 0;
	if (!(num == 0 && info->dot == 1 && info->precision == 0))
	{
		ft_putstr(ft_itoa_base_lower(num, 10));
		octa = 0;
	}
}

int			check_u_flags(long long num, t_type *info)
{
	char	*octa;
	int		precision_width_diff;
	int		octa_len;
	int		output_len;

	output_len = check_output_length(num, info);
	octa = ft_itoa_base_lower(num, 10);
	octa_len = ft_strlen(octa);
	precision_width_diff = info->width - info->precision;
	if (info->minus == 1)
		u_yes_minus(info, num, octa_len, octa);
	if (info->minus == 0)
		u_no_minus(info, num, octa_len, octa);
	return (output_len);
}

int			print_u(va_list ap, t_type *info)
{
	int					length;
	unsigned long long	number;

	number = va_arg(ap, unsigned long long);
	if (info->hh == 1)
		length = check_u_flags((unsigned char)number, info);
	else if (info->h == 1)
		length = check_u_flags((unsigned short)number, info);
	else if (info->ll == 1)
		length = check_u_flags((unsigned long long)number, info);
	else if (info->l == 1)
		length = check_u_flags((unsigned long)number, info);
	else
		length = check_u_flags((unsigned int)number, info);
	return (length);
}
