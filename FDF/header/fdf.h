/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:51:12 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/02/20 12:20:28 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../libft/headers/libft.h"
# include "mlx.h"

# define FT_ABS(x) ((x) < 0 ? (-x) : (x))

typedef struct		s_linepoints
{
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				delta_x;
	int				delta_y;
	int				coordinate_x_start;
	int				coordinate_y_start;
	int				coordinate_x_end;
	int				coordinate_y_end;
	int				t_point;
}					t_linepoints;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				hight;
	int				hypotenuse;
}					t_window;

typedef struct		s_iso
{
	int				short_line;
	int				long_line;
	int				***iso_coordinates;
}					t_iso;

typedef struct		s_parallel
{
	int				short_line;
	int				long_line;
	int				***parallel_coordinates;
}					t_parallel;

typedef struct		s_rotate_array
{
	double			***rotate_coordinates;
}					t_rotate_array;

typedef struct		s_map
{
	char			***file_arrays;
	int				file_lines;
	int				columns;
	int				output_hight;
	double			current_hight;
	int				projection;
	int				most_common_value;
	t_iso			iso;
	t_parallel		parallel;
	t_rotate_array	rotate_array;
}					t_map;

typedef struct		s_image
{
	void			*img_ptr;
	char			*img_buffer;
}					t_image;

typedef struct		s_mouse
{
	int				is_pressed;
	int				previous_x;
	int				previous_y;
}					t_mouse;

typedef struct		s_rotate
{
	double			x_angle;
	double			y_angle;
	int				z_angle;
	double			origin_x;
	double			origin_y;
	int				direction;
}					t_rotate;

typedef struct		s_master
{
	t_map			map;
	t_window		window;
	t_image			image;
	t_mouse			mouse;
	t_rotate		rotate;
	int				move_x;
	int				move_y;
	int				zoom;
	int				backround_color;
	int				line_color;
	int				color;
	int				color_count;
}					t_master;
/*
**      FDF_MAIN.C
*/
int					main(int argc, char **argv);
char				*fdf_read(int file_lines, char **str);
int					fdf_print(t_master *master);
void				fdf_print_two(t_master *master);
void				set_master_values(t_master *master, int file_lines);
/*
**      MAKE_EMPTY.C
*/
char				*make_empty_iso_coordinate_array(t_master *master);
char				*make_empty_parallel_coordinate_array(t_master *master);
char				*make_empty_rotate_coordinate_array(t_master *master);
void				make_geometry(t_master *master);
/*
**      DRAW_LINE.C
*/
int					draw_line(t_master *master);
int					draw_line2(t_master *master, t_linepoints *linepoint);
int					draw_line3(t_master *master, t_linepoints *linepoint);
void				draw_helper_one(t_linepoints *linepoint, int *x, int *y);
int					check_percentage(int percent, int start_hight,
					int end_hight, int direction);
/*
**      DRAW_PROJECTION.C
*/
void				draw_projection_one(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
void				draw_projection_two(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
void				draw_projection_three(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
/*
**      COLOR.C
*/
int					print_color(t_master *master,
					t_linepoints *linepoint, int color_count);
void				color_helper_two(t_master *master,
					t_linepoints *linepoint, int x, int y);
void				color_helper(t_linepoints *linepoint,
					int *error, int *x, int *y);
void				assign_color_to_bits(t_master *master,
					int x, int y, int color);
/*
**      MAKE_ISO.C
*/
void				fill_iso_coordinate_array(t_master *master,
					float angle, float hypotenuse);
void				fill_iso_coordinate_array_two(t_master *master,
					int column, int row);
void				fill_parallel_coordinate_array(t_master *master,
					float hypotenuse);
void				give_iso_height(t_master *master);
void				give_parallel_height(t_master *master);
/*
**      ROTATE.C
*/
void				fill_rotate_coordinate_array(t_master *master);
void				give_rotate_hight(t_master *master);
void				give_rotate_hight_two(t_master *master, int c, int r);
int					assign_line_draw_points_rotate_horizontal(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
int					assign_line_draw_points_rotate_vertical(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
/*
**      ASSIGN_LINEPOINTS.C
*/
int					assign_line_draw_points_iso_vertical(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
int					assign_line_draw_points_iso_horizontal(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
int					assign_line_draw_points_parallel_vertical(t_master *master,
					t_linepoints *linepoint, int cols, int rows);
int					assign_line_draw_points_parallel_horizontal(t_master
					*master, t_linepoints *linepoint, int cols, int rows);
/*
**      COMMANDS.C
*/
int					keycode(int keycode, t_master *master);
void				change_projection(t_master *master);
void				move_picture(t_master *master, int keycode);
void				determine_origin(t_master *master);
/*
**      COMMANDS_TWO.C
*/
void				zoom_picture(t_master *master, int keycode);
void				zoom_out(t_master *master, int keycode);
void				make_higher(t_master *master);
void				make_lower(t_master *master);
/*
**      ADJUST_ARRAY.C
*/
void				clean_array(char **str);
int					define_most_common(t_master *master);
int					give_biggest(int *values);
void				count_words(t_master *master);
/*
**      MOUSE.C
*/
int					mouse_press(int button, int x, int y, t_master *master);
int					mouse_move(int x, int y, t_master *master);
int					mouse_release(int button, int x, int y, t_master *master);
void				rotate(t_master *master, double difference);
void				rotate_helper(t_master *master, int column,
					int row, double difference);
/*
**      WINDOW.C
*/
void				color_whole_image(t_master *master);
void				color_exit_button(t_master *master, int index, int color);
void				determine_window_size(t_master *master);
void				put_text_in_window(t_master *master);
void				update_window(t_master *master);

#endif
