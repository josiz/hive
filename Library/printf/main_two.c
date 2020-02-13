/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:17:26 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 14:50:30 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int			check_len_flags_two(const char *str, t_type *info)
{
	if (*(str - 1) == 'l')
	{
		info->l = 1;
		return (1);
	}
	if (*(str - 1) == 'L')
	{
		info->bigl = 1;
		return (1);
	}
	return (0);
}

int			check_len_flags(const char *str, t_type *info)
{
	if ((*(str - 1) == 'h') && (*(str - 2) == 'h'))
	{
		info->hh = 1;
		return (2);
	}
	if (*(str - 1) == 'h')
	{
		info->h = 1;
		return (1);
	}
	if ((*(str - 1) == 'l') && (*(str - 2) == 'l'))
	{
		info->ll = 1;
		return (2);
	}
	check_len_flags_two(str, info);
	return (0);
}

const char	*check_numbers(const char *str, t_type *info)
{
	if (*str >= '1' && *str <= '9')
	{
		if ((str = count_numbers_width(str, info)) == NULL)
			return (NULL);
	}
	if (*str == '.')
	{
		info->dot = 1;
		str++;
		if (*str >= '0' && *str <= '9')
		{
			if ((str = count_numbers_precision(str, info)) == NULL)
				return (NULL);
		}
	}
	return (str);
}

const char	*count_numbers_width(const char *str, t_type *info)
{
	int		count;
	int		counter;
	int		width;
	char	*a;

	count = 0;
	counter = 0;
	while (*(str + count) >= '0' && *(str + count) <= '9')
		count++;
	if (!(a = (char*)malloc((count + 1) * sizeof(char))))
		return (NULL);
	while (counter < count)
	{
		a[counter] = *(str);
		counter++;
		str++;
	}
	a[counter] = '\0';
	width = ft_atoi(a);
	free(a);
	info->width = width;
	return (str);
}

const char	*count_numbers_precision(const char *str, t_type *info)
{
	int		count;
	int		counter;
	int		precision;
	char	*a;

	count = 0;
	counter = 0;
	while (*(str + count) >= '0' && *(str + count) <= '9')
		count++;
	if (!(a = (char*)malloc((count + 1) * sizeof(char))))
		return (NULL);
	while (counter < count)
	{
		a[counter] = *(str);
		counter++;
		str++;
	}
	a[counter] = '\0';
	precision = ft_atoi(a);
	free(a);
	info->precision = precision;
	return (str);
}
