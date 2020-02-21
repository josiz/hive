/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:22:20 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:57:54 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		keycode(int keycode, t_master *master)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
		make_higher(master);
	if (keycode == 125)
		make_lower(master);
	if (keycode == 35)
		change_projection(master);
	if (keycode == 86 || keycode == 91 || keycode == 88 || keycode == 84
			|| keycode == 89 || keycode == 92 || keycode == 83 || keycode == 85)
		move_picture(master, keycode);
	if (keycode == 6 || keycode == 7)
		zoom_picture(master, keycode);
	return (0);
}

void	move_picture(t_master *master, int keycode)
{
	if (keycode == 86 || keycode == 89 || keycode == 83)
		master->move_x -= 10;
	if (keycode == 91 || keycode == 89 || keycode == 92)
		master->move_y -= 10;
	if (keycode == 88 || keycode == 92 || keycode == 85)
		master->move_x += 10;
	if (keycode == 84 || keycode == 83 || keycode == 85)
		master->move_y += 10;
	color_whole_image(master);
	draw_line(master);
	mlx_put_image_to_window(master->window.mlx_ptr,
			master->window.win_ptr, master->image.img_ptr, 0, 0);
	put_text_in_window(master);
	determine_origin(master);
}

void	change_projection(t_master *master)
{
	if (master->map.projection == 0)
		master->map.projection = 1;
	else if (master->map.projection == 1)
		master->map.projection = 2;
	else
		master->map.projection = 0;
	master->map.current_hight = 0;
	update_window(master);
	master->map.projection == 0 ? mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, ((master->window.width / 2) - 90), 50,
			0xFFFFFF, "ROTATE WITH MOUSE") : 0;
	master->map.projection == 1 ? mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, ((master->window.width / 2) - 100), 50,
			0xFFFFFF, "PARALLEL PROJECTION") : 0;
	master->map.projection == 2 ? mlx_string_put(master->window.mlx_ptr,
			master->window.win_ptr, ((master->window.width / 2) - 105), 50,
			0xFFFFFF, "ISOMETRIC PROJECTION") : 0;
}

void	determine_origin(t_master *master)
{
	master->rotate.origin_x = (double)master->map.rotate_array.
		rotate_coordinates[master->map.columns / 2]
		[master->map.file_lines / 2][0];
	master->rotate.origin_y = (double)master->map.rotate_array.
		rotate_coordinates[master->map.columns / 2]
		[master->map.file_lines / 2][1];
}
