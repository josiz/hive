/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:03:27 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:57:26 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fill_rotate_coordinate_array(t_master *master)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	while (column < master->map.columns)
	{
		while (row < master->map.file_lines)
		{
			master->map.rotate_array.rotate_coordinates[column][row][0] =
				(double)((column * master->window.hypotenuse));
			master->map.rotate_array.rotate_coordinates[column][row][1] =
				(double)(row * master->window.hypotenuse);
			master->map.rotate_array.rotate_coordinates[column][row][2] =
				(double)ft_atoi(master->map.file_arrays[row][column]);
			master->map.rotate_array.rotate_coordinates[column][row][3] =
				(double)ft_atoi(master->map.file_arrays[row][column]);
			row++;
		}
		row = 0;
		column++;
	}
}

void	give_rotate_hight(t_master *master)
{
	int c;
	int r;

	c = -1;
	r = -1;
	while (++c < master->map.file_lines)
	{
		while (++r < master->map.columns)
		{
			master->map.rotate_array.rotate_coordinates[r][c][0] -=
				(double)(master->rotate.origin_x);
			master->map.rotate_array.rotate_coordinates[r][c][1] -=
				(double)(master->rotate.origin_y);
			give_rotate_hight_two(master, c, r);
		}
		r = -1;
	}
}

void	give_rotate_hight_two(t_master *master, int c, int r)
{
	if ((ft_atoi(master->map.file_arrays[c][r]) -
				master->map.most_common_value) != 0)
	{
		master->map.rotate_array.rotate_coordinates[r][c][2] -=
			(double)((master->map.current_hight *
						(ft_atoi(master->map.file_arrays[c][r]))));
		master->map.rotate_array.rotate_coordinates[r][c][3] +=
			(double)((master->map.current_hight *
						(ft_atoi(master->map.file_arrays[c][r]))));
	}
	else
		master->map.iso.iso_coordinates[r][c][2] = 0;
}

int		assign_line_draw_points_rotate_horizontal(t_master *master,
		t_linepoints *linepoint, int cols, int rows)
{
	if (cols < master->map.columns - 1)
	{
		linepoint->x_start = master->map.rotate_array.rotate_coordinates[cols]
			[rows][0] + master->move_x + 600;
		linepoint->x_end = master->map.rotate_array.rotate_coordinates[cols + 1]
			[rows][0] + master->move_x + 600;
		linepoint->y_start = master->map.rotate_array.rotate_coordinates[cols]
			[rows][1] + master->move_y + 400;
		linepoint->y_end = master->map.rotate_array.rotate_coordinates[cols + 1]
			[rows][1] + master->move_y + 400;
		linepoint->coordinate_x_start = cols;
		linepoint->coordinate_x_end = cols + 1;
		linepoint->coordinate_y_start = rows;
		linepoint->coordinate_y_end = rows;
		linepoint->delta_x = linepoint->x_end - linepoint->x_start;
		linepoint->delta_y = linepoint->y_end - linepoint->y_start;
	}
	return (0);
}

int		assign_line_draw_points_rotate_vertical(t_master *master,
		t_linepoints *linepoint, int cols, int rows)
{
	int row;

	row = (master->map.file_lines - 1) - rows;
	if (rows < master->map.file_lines - 1)
	{
		linepoint->x_start = master->map.rotate_array.rotate_coordinates[cols]
			[row][0] + master->move_x + 600;
		linepoint->x_end = master->map.rotate_array.rotate_coordinates[cols]
			[row - 1][0] + master->move_x + 600;
		linepoint->y_start = master->map.rotate_array.rotate_coordinates[cols]
			[row][1] + master->move_y + 400;
		linepoint->y_end = master->map.rotate_array.rotate_coordinates[cols]
			[row - 1][1] + master->move_y + 400;
		linepoint->delta_x = linepoint->x_end - linepoint->x_start;
		linepoint->delta_y = linepoint->y_end - linepoint->y_start;
		linepoint->delta_x = FT_ABS(linepoint->delta_x);
		linepoint->delta_y = FT_ABS(linepoint->delta_y);
		linepoint->coordinate_x_start = cols;
		linepoint->coordinate_x_end = cols;
		linepoint->coordinate_y_start = row;
		linepoint->coordinate_y_end = row - 1;
	}
	return (0);
}
