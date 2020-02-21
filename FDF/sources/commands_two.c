/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:56:48 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/19 15:58:18 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	zoom_picture(t_master *master, int keycode)
{
	if (keycode == 6)
	{
		if (master->window.hypotenuse > 100)
		{
			mlx_string_put(master->window.mlx_ptr, master->window.win_ptr,
					5, 110, 100100100, "MAX ZOOM IN!");
			return ;
		}
		master->window.hypotenuse += 2;
		fill_iso_coordinate_array(master, 30, master->window.hypotenuse);
		fill_parallel_coordinate_array(master, master->window.hypotenuse);
		fill_rotate_coordinate_array(master);
		update_window(master);
	}
	zoom_out(master, keycode);
}

void	zoom_out(t_master *master, int keycode)
{
	if (keycode == 7)
	{
		if (master->window.hypotenuse < 6)
		{
			mlx_string_put(master->window.mlx_ptr, master->window.win_ptr,
					5, 110, 100100100, "MAX ZOOM OUT!");
			return ;
		}
		master->window.hypotenuse -= 2;
		fill_iso_coordinate_array(master, 30, master->window.hypotenuse);
		fill_parallel_coordinate_array(master, master->window.hypotenuse);
		fill_rotate_coordinate_array(master);
		update_window(master);
	}
}

void	make_higher(t_master *master)
{
	master->map.current_hight = master->map.current_hight > 0 ?
		0 : master->map.current_hight;
	master->map.output_hight = -1;
	master->map.current_hight -= 1;
	update_window(master);
}

void	make_lower(t_master *master)
{
	master->map.current_hight = master->map.current_hight < 0 ?
		0 : master->map.current_hight;
	master->map.output_hight = 1;
	master->map.current_hight += 1;
	update_window(master);
}
