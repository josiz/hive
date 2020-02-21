/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:09:23 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:53:52 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	draw_projection_one(t_master
		*master, t_linepoints *linepoint, int cols, int rows)
{
	assign_line_draw_points_parallel_horizontal(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
	assign_line_draw_points_parallel_vertical(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
}

void	draw_projection_two(t_master
		*master, t_linepoints *linepoint, int cols, int rows)
{
	assign_line_draw_points_iso_horizontal(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
	assign_line_draw_points_iso_vertical(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
}

void	draw_projection_three(t_master
		*master, t_linepoints *linepoint, int cols, int rows)
{
	assign_line_draw_points_rotate_horizontal(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
	assign_line_draw_points_rotate_vertical(master, linepoint, cols, rows);
	draw_line3(master, linepoint);
}
