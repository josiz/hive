/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:54:39 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/17 16:12:54 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int	ft_itoa_base_test_two(long long num)
{
	if (num == 0)
	{
		ft_putstr("0");
		return (1);
	}
	return (0);
}