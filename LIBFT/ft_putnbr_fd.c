/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:36:38 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/21 15:30:51 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = 0;
	if (n >= 0)
		i = n;
	if (n < 0)
	{
		i = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
		ft_putnbr_fd((i / 10), fd);
	ft_putchar_fd(((i % 10) + '0'), fd);
}
