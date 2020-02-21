/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_linepoints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:52 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:56:15 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		assign_line_draw_points_iso_horizontal(t_master *master
		, t_linepoints *linepoint, int cols, int rows)
{
	if (cols < master->map.columns - 1)
	{
		linepoint->x_start = master->map.iso.iso_coordinates[cols]
			[rows][0] + master->move_x + 200;
		linepoint->x_end = master->map.iso.iso_coordinates[cols + 1]
			[rows][0] + master->move_x + 200;
		linepoint->y_start = master->map.iso.iso_coordinates[cols]
			[rows][1] + master->move_y + 200;
		linepoint->y_end = master->map.iso.iso_coordinates[cols + 1]
			[rows][1] + master->move_y + 200;
		linepoint->coordinate_x_start = cols;
		linepoint->coordinate_x_end = cols + 1;
		linepoint->coordinate_y_start = rows;
		linepoint->coordinate_y_end = rows;
		linepoint->delta_x = linepoint->x_end - linepoint->x_start;
		linepoint->delta_y = linepoint->y_end - linepoint->y_start;
	}
	return (0);
}

int		assign_line_draw_points_iso_vertical(t_master *master
		, t_linepoints *linepoint, int cols, int rows)
{
	int row;

	row = (master->map.file_lines - 1) - rows;
	if (rows < master->map.file_lines - 1)
	{
		linepoint->x_start = master->map.iso.iso_coordinates[cols]
			[row][0] + master->move_x + 200;
		linepoint->x_end = master->map.iso.iso_coordinates[cols]
			[row - 1][0] + master->move_x + 200;
		linepoint->y_start = master->map.iso.iso_coordinates[cols]
			[row][1] + master->move_y + 200;
		linepoint->y_end = master->map.iso.iso_coordinates[cols]
			[row - 1][1] + master->move_y + 200;
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

int		assign_line_draw_points_parallel_horizontal(t_master *master,
		t_linepoints *linepoint, int cols, int rows)
{
	if (cols < master->map.columns - 1)
	{
		linepoint->x_start = master->map.parallel.parallel_coordinates[cols]
			[rows][0] + master->move_x + 200;
		linepoint->x_end = master->map.parallel.parallel_coordinates[cols + 1]
			[rows][0] + master->move_x + 200;
		linepoint->y_start = master->map.parallel.parallel_coordinates[cols]
			[rows][1] + master->move_y + 200;
		linepoint->y_end = master->map.parallel.parallel_coordinates[cols + 1]
			[rows][1] + master->move_y + 200;
		linepoint->coordinate_x_start = cols;
		linepoint->coordinate_x_end = cols + 1;
		linepoint->coordinate_y_start = rows;
		linepoint->coordinate_y_end = rows;
		linepoint->delta_x = linepoint->x_end - linepoint->x_start;
		linepoint->delta_y = linepoint->y_end - linepoint->y_start;
	}
	return (0);
}

int		assign_line_draw_points_parallel_vertical(t_master *master,
		t_linepoints *linepoint, int cols, int rows)
{
	int row;

	row = (master->map.file_lines - 1) - rows;
	if (rows < master->map.file_lines - 1)
	{
		linepoint->x_start = master->map.parallel.parallel_coordinates[cols]
			[row][0] + master->move_x + 200;
		linepoint->x_end = master->map.parallel.parallel_coordinates[cols]
			[row - 1][0] + master->move_x + 200;
		linepoint->y_start = master->map.parallel.parallel_coordinates[cols]
			[row][1] + master->move_y + 200;
		linepoint->y_end = master->map.parallel.parallel_coordinates[cols]
			[row - 1][1] + master->move_y + 200;
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
