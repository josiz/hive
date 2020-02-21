/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:29:37 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/13 17:21:20 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int			print_p(va_list ap, t_type *info)
{
	long long	pointer;
	int			pointer_length;
	int			print_spaces_length;

	pointer = va_arg(ap, long long);
	pointer_length = ft_strlen(ft_itoa_base_lower(pointer, 16)) + 2;
	print_spaces_length = pointer_length >= info->width ? 0
		: (info->width - pointer_length);
	if (info->minus == 1)
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base_lower(pointer, 16));
		while (print_spaces_length-- > 0)
			write(1, " ", 1);
	}
	while (print_spaces_length-- > 0)
		write(1, " ", 1);
	if (info->minus == 0)
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base_lower(pointer, 16));
	}
	return (pointer_length >= info->width ? pointer_length : info->width);
}

int			print_c(va_list ap, t_type *info)
{
	char	c;
	int		print_length;
	int		ret;

	c = va_arg(ap, int);
	print_length = 0;
	if (info->minus == 1)
		ft_putchar(c);
	print_length = info->width;
	ret = print_length;
	print_length -= info->width > 0 ? 1 : 0;
	while (print_length-- > 0)
		write(1, " ", 1);
	if (info->minus == 0)
		ft_putchar(c);
	return (ret += info->width > 0 ? 0 : 1);
}

static void	print_s2(t_type *info, char *s, int space_print_length)
{
	if (info->dot == 0 && info->minus == 1)
		ft_putstr(s);
	while (space_print_length-- > 0)
		write(1, " ", 1);
	if (info->dot == 0 && info->minus == 0)
		ft_putstr(s);
	if (info->minus == 0 && info->dot == 1)
		(((int)ft_strlen(s) >= info->precision) ?
		ft_putnstr(s, info->precision) : ft_putstr(s));
}

static int	print_s_helper(t_type *info, char *s)
{
	if (s == '\0')
	{
		if (info->precision > 6)
			info->precision = 6;
		return (1);
	}
	return (0);
}

int			print_s(va_list ap, t_type *info)
{
	char	*s;
	int		space_print_length;
	int		ret;
	int		str_len;
	char	*nul;

	nul = declare_null();
	s = va_arg(ap, char*);
	if (print_s_helper(info, s) == 1)
		s = nul;
	str_len = (int)ft_strlen(s) >= info->precision ?
	info->precision : (int)ft_strlen(s);
	space_print_length = info->width - str_len;
	if (info->dot == 0)
		space_print_length = info->width - (int)ft_strlen(s);
	if (info->minus == 1 && info->dot == 1)
		(((int)ft_strlen(s) >= info->precision) ?
		ft_putnstr(s, info->precision) : ft_putstr(s));
	ret = str_len >= info->width ? str_len : info->width;
	if (info->dot == 0)
		ret = (int)ft_strlen(s) >= info->width ?
		(int)ft_strlen(s) : info->width;
	print_s2(info, s, space_print_length);
	free(nul);
	return (ret);
}
