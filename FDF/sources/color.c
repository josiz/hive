/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:21 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:55:52 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		print_color(t_master *master, t_linepoints *linepoint, int c)
{
	int		dist;
	int		hight_difference;
	int		start_hight;
	int		end_hight;
	int		p;

	start_hight = master->map.iso.iso_coordinates[linepoint->coordinate_x_start]
		[linepoint->coordinate_y_start][2];
	end_hight = master->map.iso.iso_coordinates[linepoint->coordinate_x_end]
		[linepoint->coordinate_y_end][2];
	hight_difference = FT_ABS(end_hight - start_hight);
	dist = linepoint->delta_x >= linepoint->delta_y ? linepoint->delta_x :
		linepoint->delta_y;
	if (linepoint->delta_x >= linepoint->delta_y)
		p = (((c * 1000) / (linepoint->delta_x + 1)) * 100) / 1000;
	else
		p = (((c * 1000) / (linepoint->delta_y + 1)) * 100) / 1000;
	if (hight_difference != 0 && linepoint->y_start >= linepoint->y_end)
		return (FT_ABS(start_hight) * 0x0100 + 0xFF0000 -
				(check_percentage(p, start_hight, end_hight, 1) * 0x0100));
	else if (hight_difference != 0 && linepoint->y_start < linepoint->y_end)
		return (FT_ABS(start_hight) * 0x0100 + 0xFF0000 +
				(check_percentage(p, start_hight, end_hight, 0) * 0x0100));
	else
		return (FT_ABS(start_hight) * 0x0100 + 0xFF0000);
}

void	color_helper(t_linepoints *linepoint, int *error, int *x, int *y)
{
	*error += (linepoint->delta_x <= linepoint->delta_y ?
			linepoint->delta_x : linepoint->delta_y);
	if (*error >= (linepoint->delta_x >= linepoint->delta_y ?
				linepoint->delta_x : linepoint->delta_y))
	{
		*x += linepoint->delta_x <= linepoint->delta_y ? 1 : 0;
		*y += linepoint->delta_x > linepoint->delta_y ? linepoint->t_point : 0;
		*error -= (linepoint->delta_x >= linepoint->delta_y ?
				linepoint->delta_x : linepoint->delta_y);
	}
	if (linepoint->delta_x <= linepoint->delta_y)
		*y += linepoint->y_start >= linepoint->y_end ? -1 : 1;
	else
		*x += 1;
}

void	color_helper_two(t_master *master,
t_linepoints *linepoint, int x, int y)
{
	if (((y * (4 * master->window.width)) + 4 * x) >= 0 &&
			((y * (4 * master->window.width)) + 4 * x) <=
			(((master->window.hight)
					* (4 * master->window.width)) + 4 * x) &&
			((y * (4 * master->window.width)) + 4 * x) >=
			y * (4 * master->window.width)
			&& ((y * (4 * master->window.width)) + 4 * x) < (((y + 1) *
					(4 * master->window.width))))
	{
		master->color = print_color(master, linepoint, master->color_count);
		if (!(master->color <= 0xFFFF00 && master->color >= 0xFF0000))
			master->color = 0xFFFF00;
		assign_color_to_bits(master, x, y, master->color);
	}
}

void	assign_color_to_bits(t_master *master, int x, int y, int color)
{
	master->image.img_buffer[(y * (4 * master->window.width)) + 4 * x] =
		(color);
	master->image.img_buffer[(y * (4 * master->window.width)) + 4 * x + 1] =
		(color) >> 8;
	master->image.img_buffer[(y * (4 * master->window.width)) + 4 * x + 2] =
		(color) >> 16;
	master->image.img_buffer[(y * (4 * master->window.width)) + 4 * x + 3] =
		(color) >> 24;
}
