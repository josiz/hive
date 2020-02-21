/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:29:33 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:50:24 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		mouse_press(int button, int x, int y, t_master *master)
{
	if (button == 1 && x < 100 && y < 30)
		exit(1);
	master->mouse.is_pressed = 1;
	if (mlx_hook(master->window.win_ptr, 6, 0, mouse_move, master) == 1)
		return (1);
	return (0);
}

int		mouse_move(int x, int y, t_master *master)
{
	determine_origin(master);
	if (master->mouse.is_pressed == 1 && master->mouse.previous_y !=
			0 && master->mouse.previous_x != x)
	{
		master->rotate.direction = 0;
		rotate(master, (x - master->mouse.previous_x));
	}
	if (master->mouse.is_pressed == 1 && master->mouse.previous_y !=
			0 && master->mouse.previous_y != y)
	{
		master->rotate.direction = 1;
		rotate(master, (y - master->mouse.previous_y));
	}
	master->mouse.previous_x = x;
	master->mouse.previous_y = y;
	master->map.current_hight = 0;
	update_window(master);
	return (0);
}

int		mouse_release(int button, int x, int y, t_master *master)
{
	x = 0;
	y = 0;
	button = 0;
	master->mouse.is_pressed = 0;
	master->mouse.previous_x = 0;
	master->mouse.previous_y = 0;
	return (0);
}

void	rotate(t_master *master, double difference)
{
	int		column;
	int		row;
	double	origin_x;
	double	origin_y;

	origin_x = (double)master->rotate.origin_x;
	origin_y = (double)master->rotate.origin_y;
	row = 0;
	column = 0;
	while (column < master->map.columns)
	{
		while (row < master->map.file_lines)
		{
			rotate_helper(master, column, row, difference);
			row++;
		}
		row = 0;
		column++;
	}
}

void	rotate_helper(t_master *master, int column, int row, double difference)
{
	double	x;
	double	y;
	double	z;
	int		i;

	i = master->rotate.direction;
	x = (double)master->map.rotate_array.rotate_coordinates[column][row][0];
	y = (double)master->map.rotate_array.rotate_coordinates[column][row][1];
	z = (double)master->map.rotate_array.rotate_coordinates[column][row][3];
	if (i == 1)
	{
		master->map.rotate_array.rotate_coordinates[column][row][1] = (double)
		(((y) * cos((difference * 0.007)) + (z * sin(difference * 0.007))));
		master->map.rotate_array.rotate_coordinates[column][row][3] = (double)
		((-(y) * sin(difference * 0.007)) + (z * cos(difference * 0.007)));
	}
	else
	{
		master->map.rotate_array.rotate_coordinates[column][row][0] = (double)
		((((x)) * cos(difference * 0.007) + (z * sin(difference * 0.007))));
		master->map.rotate_array.rotate_coordinates[column][row][3] = (double)
		(((-(x)) * sin(difference * 0.007)) + (z * cos(difference * 0.007)));
	}
}
