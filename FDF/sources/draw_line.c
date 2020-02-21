/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:51:26 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:55:24 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		check_percentage(int percent, int start_hight,
		int end_hight, int direction)
{
	if (direction == 0)
	{
		if (FT_ABS(start_hight) >= 100 || start_hight < 1)
			return ((percent * (FT_ABS(end_hight) -
			FT_ABS(start_hight))) / 100);
		else if (FT_ABS(start_hight) < 10)
			return (0);
		else
			return (((percent * (FT_ABS(end_hight) -
								FT_ABS(start_hight))) / 100));
	}
	else
	{
		if (FT_ABS(end_hight) >= 100 || start_hight < 1)
			return ((percent * (FT_ABS(start_hight) -
			FT_ABS(end_hight))) / 100);
		else if (FT_ABS(end_hight) < 10)
			return (0);
		else
			return (((percent * (FT_ABS(start_hight) -
			FT_ABS(end_hight))) / 100));
	}
}

void	draw_helper_one(t_linepoints *linepoint, int *x, int *y)
{
	int temp1;
	int temp2;

	if (linepoint->x_start <= linepoint->x_end)
	{
		*x = linepoint->x_start;
		*y = linepoint->y_start;
	}
	else
	{
		temp1 = linepoint->x_start;
		temp2 = linepoint->y_start;
		linepoint->x_start = linepoint->x_end;
		linepoint->y_start = linepoint->y_end;
		linepoint->x_end = temp1;
		linepoint->y_end = temp2;
	}
	*x = linepoint->x_start;
	*y = linepoint->y_start;
	linepoint->delta_x = linepoint->x_end - linepoint->x_start;
	if (linepoint->y_start <= linepoint->y_end)
		linepoint->delta_y = linepoint->y_end - linepoint->y_start;
	else
		linepoint->delta_y = linepoint->y_start - linepoint->y_end;
}

int		draw_line3(t_master *master, t_linepoints *linepoint)
{
	int x;
	int y;
	int error;

	master->color = 0xFFFF00;
	master->color_count = 0;
	draw_helper_one(linepoint, &x, &y);
	linepoint->t_point = linepoint->y_start <= linepoint->y_end ? 1 : -1;
	error = (linepoint->delta_x >= linepoint->delta_y ? linepoint->delta_x :
			linepoint->delta_y) / 2;
	while (FT_ABS(x) <= linepoint->x_end)
	{
		if ((linepoint->t_point == 1 && y > linepoint->y_end) ||
				(linepoint->t_point == -1 && y < linepoint->y_end))
			break ;
		master->color_count++;
		color_helper_two(master, linepoint, x, y);
		color_helper(linepoint, &error, &x, &y);
	}
	return (0);
}

int		draw_line2(t_master *master, t_linepoints *linepoint)
{
	int cols;
	int rows;
	int horizont;

	horizont = 0;
	cols = 0;
	rows = 0;
	while (cols < master->map.columns)
	{
		while (rows < master->map.file_lines)
		{
			if (master->map.projection == 1)
				draw_projection_one(master, linepoint, cols, rows);
			else if (master->map.projection == 2)
				draw_projection_two(master, linepoint, cols, rows);
			else
				draw_projection_three(master, linepoint, cols, rows);
			rows++;
		}
		cols++;
		rows = 0;
	}
	return (0);
}

int		draw_line(t_master *master)
{
	t_linepoints linepoint;

	draw_line2(master, &linepoint);
	return (0);
}
