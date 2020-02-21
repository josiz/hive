/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:23:54 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:33:19 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		define_most_common(t_master *master)
{
	int		values[10000];
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = -1;
	while (i++ < 10000)
		values[i] = 0;
	while (x < master->map.columns)
	{
		while (y < master->map.file_lines)
		{
			i = ft_atoi(master->map.file_arrays[y][x]);
			if (ft_atoi(master->map.file_arrays[y][x]) >= 0)
				values[i] += 1;
			y++;
		}
		y = 0;
		x++;
	}
	i = give_biggest(values);
	return (i);
}

int		give_biggest(int *values)
{
	int		biggest;
	int		index;
	int		ret;

	index = 0;
	biggest = 0;
	while (index < 100)
	{
		if (values[index] > values[biggest])
		{
			biggest = index;
			ret = index;
		}
		index++;
	}
	if (values[0] >= values[ret])
		ret = 0;
	return (ret);
}

void	clean_array(char **str)
{
	int		i;
	char	*a;

	i = 0;
	while (str[i] != '\0')
	{
		a = ft_strchr(str[i], ',');
		a = 0;
		free(a);
		i++;
	}
	return ;
}

void	count_words(t_master *master)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < master->map.file_lines)
	{
		while (master->map.file_arrays[i][j])
			j++;
		if (j != master->map.columns)
		{
			ft_printf("Invalid map!\n");
			exit(1);
		}
		j = 0;
		i++;
	}
	return ;
}
