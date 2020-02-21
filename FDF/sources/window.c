/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:56:54 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:56:49 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	color_whole_image(t_master *master)
{
	int i;
	int x;
	int y;
	int color;

	color = 0xFFFFFF;
	x = 0;
	y = 0;
	i = 0;
	while (x < (master->window.hight))
	{
		while (y < (master->window.width))
		{
			master->image.img_buffer[i] = (master->backround_color);
			master->image.img_buffer[i + 1] = (master->backround_color >> 8);
			master->image.img_buffer[i + 2] = (master->backround_color >> 16);
			master->image.img_buffer[i + 3] = (master->backround_color >> 24);
			if (x < 30 && y < 100)
				color_exit_button(master, i, color);
			i += 4;
			y++;
		}
		y = 0;
		x++;
	}
}

void	color_exit_button(t_master *master, int index, int color)
{
	{
		master->image.img_buffer[index] = color;
		master->image.img_buffer[index + 1] = (color >> 8);
		master->image.img_buffer[index + 2] = (color >> 16);
		master->image.img_buffer[index + 3] = (color >> 24);
	}
}

void	determine_window_size(t_master *master)
{
	if (master->map.file_lines < 20 && master->map.columns < 20)
	{
		master->window.width = 1500;
		master->window.hight = 1000;
		master->window.hypotenuse = 35 * master->zoom;
	}
	else if (master->map.file_lines < 50 && master->map.columns < 50)
	{
		master->window.width = 2000;
		master->window.hight = 1300;
		master->window.hypotenuse = 25 * master->zoom;
	}
	else
	{
		master->window.width = 2500;
		master->window.hight = 1400;
		master->window.hypotenuse = 15 * master->zoom;
	}
}

void	put_text_in_window(t_master *master)
{
	mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, 25, 5, 0xAB0000, "EXIT");
	mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, 5, 50, 0xAB0000, "ZOOM IN:  Z");
	mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, 5, 80, 0xAB0000, "ZOOM OUT: X");
	mlx_string_put(master->window.mlx_ptr, master->window.win_ptr,
			master->window.width - 250, 50, 0xAB0000, "MOVE: KEYPAD");
	mlx_string_put(master->window.mlx_ptr, master->window.win_ptr,
			master->window.width - 250, 100, 0xAB0000, "CHANGE PROJECTION: P");
}

void	update_window(t_master *master)
{
	give_iso_height(master);
	give_parallel_height(master);
	give_rotate_hight(master);
	color_whole_image(master);
	draw_line(master);
	mlx_put_image_to_window(master->window.mlx_ptr, master->window.win_ptr,
			master->image.img_ptr, 0, 0);
	put_text_in_window(master);
	determine_origin(master);
}
