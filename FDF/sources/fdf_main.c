/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:56:03 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/20 12:20:16 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		fdf_print(t_master *master)
{
	int	bits_per_pixel;
	int size_line;
	int endian;

	bits_per_pixel = 32;
	size_line = bits_per_pixel * (master->window.width);
	endian = 0;
	determine_window_size(master);
	master->window.mlx_ptr = mlx_init();
	master->window.win_ptr = mlx_new_window(master->window.mlx_ptr,
			master->window.width, master->window.hight, "jees");
	master->backround_color = 0x000000;
	make_geometry(master);
	master->image.img_ptr = mlx_new_image(master->window.mlx_ptr,
			master->window.width, master->window.hight);
	master->image.img_buffer = mlx_get_data_addr(master->image.img_ptr,
			&bits_per_pixel, &size_line, &endian);
	fdf_print_two(master);
	return (0);
}

void	fdf_print_two(t_master *master)
{
	color_whole_image(master);
	mlx_put_image_to_window(master->window.mlx_ptr, master->window.win_ptr,
			master->image.img_ptr, 0, 0);
	draw_line(master);
	mlx_put_image_to_window(master->window.mlx_ptr, master->window.win_ptr,
			master->image.img_ptr, 0, 0);
	put_text_in_window(master);
	mlx_key_hook(master->window.win_ptr, keycode, master);
	mlx_hook(master->window.win_ptr, 5, 0, mouse_release, master);
	mlx_hook(master->window.win_ptr, 4, 0, mouse_press, master);
	mlx_loop(master->window.mlx_ptr);
}

char	*fdf_read(int file_lines, char **str)
{
	char		*line;
	int			fd;
	int			index;
	t_master	master;

	index = 0;
	set_master_values(&master, file_lines);
	if (!(master.map.file_arrays = malloc((sizeof(void*) * (file_lines + 1)))))
		return (NULL);
	fd = open(*str, O_RDONLY);
	while (index < file_lines)
	{
		get_next_line(fd, &line);
		master.map.file_arrays[index] = ft_strsplit(line, ' ');
		free(line);
		clean_array(master.map.file_arrays[index]);
		index++;
	}
	while (master.map.file_arrays[0][master.map.columns])
		master.map.columns++;
	count_words(&master);
	master.map.most_common_value = define_most_common(&master);
	fdf_print(&master);
	return (0);
}

void	set_master_values(t_master *master, int file_lines)
{
	master->map.output_hight = 1;
	master->map.current_hight = 0;
	master->map.projection = 1;
	master->move_x = 100;
	master->move_y = 100;
	master->zoom = 1;
	master->mouse.is_pressed = 0;
	master->rotate.x_angle = 0;
	master->rotate.y_angle = 0;
	master->rotate.z_angle = 0;
	master->mouse.previous_x = 0;
	master->mouse.previous_y = 0;
	master->map.columns = 0;
	master->map.file_lines = file_lines;
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		file_lines;

	fd = open(argv[1], O_RDONLY);
	file_lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		file_lines++;
		free(line);
	}
	close(fd);
	if (argc == 2)
		fdf_read(file_lines, &argv[1]);
	return (0);
}
