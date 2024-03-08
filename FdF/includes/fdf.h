/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:26:33 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/28 15:26:33 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGTH 1080
# define MENU 350
# define DEFAULT_COLOR 0xec7c26

/*# define ABS(a) ((a < 0) ? -a : a)
# define MAX(a,b) ((a < b) ? b : a)
# define MIN(a,b) ((a > b) ? b : a)
# define ANGLE 0.8*/

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	rgb;
	int	is_diff;
	int	diff_r;
	int	diff_g;
	int	diff_b;
	int	color1;
	int	def_color;
}	t_colors;

typedef struct parse_list
{
	int					x;
	int					y;
	int					z;
	float				x1;
	float				y1;
	int					z1;
	double				angle;
	int					**coord;
	int					width;
	int					heigth;
	int					*color;
	int					zoom;
	int					shift_x;
	int					shift_y;
	int					scale_z;
}	t_map;

typedef struct ptr_window
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct main_struct
{
	t_map		*map;
	t_win		win;
	t_data		img;
	t_colors	rgb;
}	t_nodes;

//Free Memory && Auxiliar Functions
void	free_mem(t_map **map);
void	handle_error(t_map **map);
int		abs_value(float a);

//Draw Line *** DDA Algoithm
void	draw(t_nodes *mlx);

//Read File
void	read_coords(t_map **coord, char *argv);

//Colors
int		create_rgb(int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	set_color_values(t_nodes *mlx, int x, int y, int is_vertical);
void	set_colors(t_nodes *clr, int steps);

//Window Values
void	set_win_values(t_nodes *mlx);
void	set_zoom(t_nodes *mlx, float *x, float *y);
void	center_image(t_nodes *mlx, float *x, float *y);

//Execute the keyboard codes
int		key_exe(int keycode, t_nodes *mlx);

//Menu
void	menu(t_nodes *mlx);

#endif
