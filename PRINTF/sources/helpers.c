/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:58:04 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/14 18:09:15 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	clear_struct(t_type *info)
{
	info->hashtag = 0;
	info->zero = 0;
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = 0;
	info->hh = 0;
	info->h = 0;
	info->ll = 0;
	info->l = 0;
	info->bigl = 0;
	info->roundup = 0;
}

int		is_flag(char a)
{
	if (a == '#' || a == '0' || a == '-' ||
			a == '+' || a == ' ')
		return (1);
	return (0);
}

int		is_type(char a)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' ||
			a == 'o' || a == 'u' || a == 'x'
			|| a == 'X' || a == 'f' || a == '%')
		return (1);
	return (0);
}

int		is_len(char a)
{
	if (a == 'h' || a == 'l' || a == 'L')
		return (1);
	return (0);
}

void	putspaces_count(int i, int *count)
{
	while (i-- > 0)
	{
		write(1, " ", 1);
		*count += 1;
	}
}
