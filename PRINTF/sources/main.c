/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:07:11 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:13:15 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		check_f_helper(t_type *info, int spaces, int *ret_count)
{
	if (info->minus == 1)
		putspaces_count(spaces, ret_count);
}

void		check_flags(const char *str, t_type *info)
{
	while (is_flag(*str))
	{
		if (*str == '#')
			info->hashtag = 1;
		else if (*str == '0')
			info->zero = 1;
		else if (*str == '-')
			info->minus = 1;
		else if (*str == '+')
			info->plus = 1;
		else if (*str == ' ')
			info->space = 1;
		str++;
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_type	info;
	int		printedcount;

	clear_struct(&info);
	va_start(ap, str);
	printedcount = 0;
	while (*str)
	{
		str = gotrough1(str, &info, &printedcount, ap);
		if (str == '\0')
			return (0);
		str++;
	}
	return (printedcount);
}

const char	*gotrough1(const char *str, t_type *info, int *count, va_list ap)
{
	if (*str == '%')
	{
		str++;
		while (is_type(*str) == 0)
		{
			if (*str == '\0')
				return (str);
			str = gotrough2(str, info);
		}
		if (is_type(*str) == 1)
		{
			check_len_flags(str, info);
			*count += print_block(*str, info, ap);
			clear_struct(info);
		}
	}
	else
	{
		ft_putchar(*str);
		*count += 1;
	}
	return (str);
}

const char	*gotrough2(const char *str, t_type *info)
{
	if ((*(str) >= '1' && *(str) <= '9') || *(str) == '.')
		str = check_numbers(str, info);
	else if (is_flag(*str) == 1)
	{
		while (is_flag(*str) == 1)
		{
			check_flags(str, info);
			str++;
		}
	}
	else if (is_len(*str) == 1)
		str++;
	else if (*(str) == '$' || *(str) == '*')
		str++;
	else
		str++;
	return (str);
}
