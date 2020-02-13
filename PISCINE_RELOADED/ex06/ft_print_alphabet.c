/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:46 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/16 09:30:32 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	ft_print_alphabet(void)
{
	char a;

	a = 97;
	while (a < 123)
	{
		ft_putchar(a);
		a++;
	}
	return ;
}
