/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:12:47 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:57:07 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	give_iso_height(t_master *master)
{
	int c;
	int r;

	c = -1;
	r = -1;
	while (++c < master->map.file_lines)
	{
		while (++r < master->map.columns)
		{
			if ((ft_atoi(master->map.file_arrays[c][r]) -
						master->map.most_common_value) != 0)
			{
				master->map.iso.iso_coordinates[r][c][2] -= (master->
				map.current_hight * (ft_atoi(master->map.file_arrays[c][r])));
				master->map.iso.iso_coordinates[r][c][3] -=
					(master->map.current_hight * (ft_atoi(master->
					map.file_arrays[c][r])) / 1);
				master->map.iso.iso_coordinates[r][c][1] += (master->
				map.current_hight * (ft_atoi(master->map.file_arrays[c][r])));
			}
			else
				master->map.iso.iso_coordinates[r][c][2] = 0;
		}
		r = -1;
	}
}

void	give_parallel_height(t_master *master)
{
	int col;
	int row;

	col = -1;
	row = -1;
	while (++col < master->map.file_lines)
	{
		while (++row < master->map.columns)
		{
			if ((ft_atoi(master->map.file_arrays[col][row]) -
						master->map.most_common_value) != 0)
			{
				master->map.parallel.parallel_coordinates[row][col][3] =
					(ft_atoi(master->map.file_arrays[col][row]));
				master->map.parallel.parallel_coordinates[row][col][2] =
					(ft_atoi(master->map.file_arrays[col][row]));
				master->map.parallel.parallel_coordinates[row][col][1] +=
					master->map.current_hight *
					(ft_atoi(master->map.file_arrays[col][row]));
			}
			else
				master->map.parallel.parallel_coordinates[row][col][2] = 0;
		}
		row = -1;
	}
}

void	fill_iso_coordinate_array(t_master *master,
float angle, float hypotenuse)
{
	float	radian;
	int		row;
	int		column;

	row = -1;
	column = -1;
	radian = (angle * (M_PI / 180));
	master->map.iso.short_line = (sin(radian) * hypotenuse);
	master->map.iso.long_line = (cos(radian) * hypotenuse);
	while (++column < master->map.columns)
	{
		while (++row < master->map.file_lines)
			fill_iso_coordinate_array_two(master, column, row);
		row = -1;
	}
}

void	fill_iso_coordinate_array_two(t_master *master, int column, int row)
{
	master->map.iso.iso_coordinates[column][row][0] =
		(((master->map.file_lines - row) * master->map.iso.long_line +
		(column * master->map.iso.long_line)));
	master->map.iso.iso_coordinates[column][row][1] =
		(row * master->map.iso.short_line + column *
		master->map.iso.short_line) -
		ft_atoi(master->map.file_arrays[row][column]);
	master->map.iso.iso_coordinates[column][row][2] =
		ft_atoi(master->map.file_arrays[row][column]);
	master->map.iso.iso_coordinates[column][row][3] =
		ft_atoi(master->map.file_arrays[row][column]);
}

void	fill_parallel_coordinate_array(t_master *master, float side)
{
	int		row;
	int		column;
	float	hypotenuse;

	row = 0;
	column = 0;
	hypotenuse = sqrt(2 * (side * side));
	while (column < master->map.columns)
	{
		while (row < master->map.file_lines)
		{
			master->map.parallel.parallel_coordinates[column][row][0] =
				(((master->map.file_lines - row) * side) + (column * side));
			master->map.parallel.parallel_coordinates[column][row][1] =
				side * row - ft_atoi(master->map.file_arrays[row][column]);
			master->map.parallel.parallel_coordinates[column][row][2] =
				ft_atoi(master->map.file_arrays[row][column]);
			master->map.parallel.parallel_coordinates[column][row][3] =
				ft_atoi(master->map.file_arrays[row][column]);
			row++;
		}
		row = 0;
		column++;
	}
}
