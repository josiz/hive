/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:19:08 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/17 09:45:47 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int a;

	a = 1;
	if (nb <= 0)
		return (0);
	while (a * a < nb)
	{
		a++;
	}
	if ((nb % a) == 0)
		return (a);
	else
		return (0);
}
