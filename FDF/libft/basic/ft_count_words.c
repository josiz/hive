/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:27:39 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 17:50:33 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_count_words(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (ft_isspace(*str) == 1)
			str++;
		if (*str && ft_isspace(*str) == 0)
		{
			count++;
			while (*str && ft_isspace(*str) == 0)
				str++;
		}
	}
	return (count);
}
