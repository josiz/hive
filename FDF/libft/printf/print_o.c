/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:17:43 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 18:11:07 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

static void	o_no_minus(t_type *info, long long num, char *octa, int octa_len)
{
	if (info->hashtag == 1 && num != 0)
	{
		info->width--;
		info->precision--;
	}
	if (info->hashtag == 1 && num == 0)
		octa_len = 0;
	if (octa_len == 0 && info->dot == 1 &&
			info->width == 0 && info->precision == 0)
		octa_len++;
	if (num == 0 && info->hashtag == 1 && info->precision == 0)
		info->width--;
	if ((info->width > info->precision || info->width > octa_len) &&
			(info->zero == 0 || info->dot == 1))
		info->precision > octa_len ? putspaces(info->width -
				info->precision) : putspaces(info->width - octa_len);
	else if (info->zero == 1 && info->precision > 0)
		info->precision > octa_len ? putspaces(info->width - info->precision) :
			putspaces(info->width - octa_len);
	else if ((info->width > info->precision ||
				info->width > octa_len) && info->zero == 1)
		info->precision > octa_len ? putzero(info->width - info->precision) :
			putzero(info->width - octa_len);
	o_no_minus2(info, num, octa, octa_len);
}

static void	o_yes_minus(t_type *info, long long num, char *octa, int octa_len)
{
	if (info->hashtag == 1 && num == 0)
		info->width++;
	if (info->hashtag == 1 && num != 0)
		info->precision--;
	if (octa_len == 0 && info->dot == 1 &&
			info->width == 0 && info->precision == 0)
		octa_len++;
	info->precision > octa_len ? putzero(info->precision - octa_len) : 0;
	if ((info->hashtag == 1 && num != 0) || (info->hashtag == 1 &&
				num == 0 && info->dot == 1 && info->precision == 0))
		write(1, "0", 1);
	(info->hashtag == 1 && info->width > info->precision) ? info->width-- : 0;
	if ((!(info->dot == 1 && num == 0)))
		ft_putstr(octa);
	if (num == 0 && info->precision == 0 && info->hashtag == 1)
		putspaces(info->width - 1);
	else if (info->width > info->precision || info->width > octa_len)
		info->precision > octa_len ? putspaces(info->width -
				info->precision) : putspaces(info->width - octa_len);
}

static int	check_output_length(long long num, t_type *info)
{
	int	num_len;
	int	width_len;
	int	precision_len;
	int	hash;

	hash = 0;
	if (info->dot == 1 && num == 0 && info->hashtag == 1 &&
			info->width == 0 && info->precision == 0)
		return (1);
	if (info->dot == 1 && num == 0 && info->precision == 0)
		return (info->width);
	if (info->hashtag == 1 && num != 0)
		hash = 1;
	num_len = ft_strlen(ft_itoa_base_upper(num, 8));
	width_len = info->width;
	precision_len = info->precision;
	if (num_len >= width_len && num_len >= precision_len)
		return (num_len + hash);
	if (width_len >= num_len && width_len >= precision_len)
		return (width_len);
	else
		return (precision_len);
}

int			check_o_flags(long long num, t_type *info)
{
	char	*octa;
	int		precision_width_diff;
	int		octa_len;
	int		output_len;
	int		og_width;

	og_width = info->width;
	output_len = check_output_length(num, info);
	octa = ft_itoa_base_lower(num, 8);
	octa_len = ft_strlen(octa);
	if (info->dot == 1 && num == 0)
		octa_len = 0;
	precision_width_diff = info->width - info->precision;
	if (info->minus == 1)
		o_yes_minus(info, num, octa, octa_len);
	if (info->minus == 0)
		o_no_minus(info, num, octa, octa_len);
	return (output_len);
}

int			print_o(va_list ap, t_type *info)
{
	int					length;
	unsigned long long	number;

	number = va_arg(ap, unsigned long long);
	length = 0;
	if (info->hh == 1)
		length += check_o_flags((unsigned char)number, info);
	else if (info->h == 1)
		length += check_o_flags((unsigned short)number, info);
	else if (info->ll == 1)
		length += check_o_flags((unsigned long long)number, info);
	else if (info->l == 1)
		length += check_o_flags((unsigned long)number, info);
	else
		length += check_o_flags((unsigned int)number, info);
	return (length);
}
