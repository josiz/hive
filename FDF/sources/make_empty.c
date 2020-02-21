/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:13:20 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:46:51 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*make_empty_rotate_coordinate_array(t_master *master)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (!(master->map.rotate_array.rotate_coordinates = malloc((sizeof(void**)
						* (master->map.columns + 1)))))
		return (NULL);
	while (a < master->map.columns)
	{
		if (!(master->map.rotate_array.rotate_coordinates[a] =
		malloc((sizeof(void*) * (master->map.file_lines + 1)))))
			return (NULL);
		while (b < master->map.file_lines)
		{
			master->map.rotate_array.rotate_coordinates[a][b] =
				malloc(sizeof(double) * 5);
			b++;
		}
		master->map.rotate_array.rotate_coordinates[a][b] = 0;
		a++;
		b = 0;
	}
	master->map.rotate_array.rotate_coordinates[a] = 0;
	return (0);
}

char	*make_empty_iso_coordinate_array(t_master *master)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (!(master->map.iso.iso_coordinates = malloc((sizeof(void**)
						* (master->map.columns + 1)))))
		return (NULL);
	while (a < master->map.columns)
	{
		if (!(master->map.iso.iso_coordinates[a] = malloc((sizeof(void*)
							* (master->map.file_lines + 1)))))
			return (NULL);
		while (b < master->map.file_lines)
		{
			master->map.iso.iso_coordinates[a][b] = malloc(sizeof(int) * 5);
			b++;
		}
		master->map.iso.iso_coordinates[a][b] = 0;
		a++;
		b = 0;
	}
	master->map.iso.iso_coordinates[a] = 0;
	return (0);
}

char	*make_empty_parallel_coordinate_array(t_master *master)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (!(master->map.parallel.parallel_coordinates = malloc((sizeof(void**)
						* (master->map.columns + 1)))))
		return (NULL);
	while (a < master->map.columns)
	{
		if (!(master->map.parallel.parallel_coordinates[a] =
		malloc((sizeof(void*) * (master->map.file_lines + 1)))))
			return (NULL);
		while (b < master->map.file_lines)
		{
			master->map.parallel.parallel_coordinates[a][b] =
			malloc(sizeof(int) * 5);
			b++;
		}
		master->map.parallel.parallel_coordinates[a][b] = 0;
		a++;
		b = 0;
	}
	master->map.parallel.parallel_coordinates[a] = 0;
	return (0);
}

void	make_geometry(t_master *master)
{
	make_empty_iso_coordinate_array(master);
	make_empty_parallel_coordinate_array(master);
	make_empty_rotate_coordinate_array(master);
	fill_iso_coordinate_array(master, 30, master->window.hypotenuse);
	fill_parallel_coordinate_array(master, master->window.hypotenuse);
	fill_rotate_coordinate_array(master);
	give_iso_height(master);
	give_parallel_height(master);
	give_rotate_hight(master);
	determine_origin(master);
}
