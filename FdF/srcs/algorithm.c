/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:15:27 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/28 15:07:58 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_altitude(t_nodes *mlx, int x, int y)
{
	mlx->map->z = mlx->map->coord[y][x];
	mlx->map->z1 = mlx->map->coord[(int)mlx->map->y1][(int)mlx->map->x1];
	if (mlx->map->z)
		mlx->map->z *= mlx->map->scale_z;
	if (mlx->map->z1)
		mlx->map->z1 *= mlx->map->scale_z;
}

/* Function to convert from 2D to 3D using isometric projection */

static void	convert_isometric(t_map *rot, float *x, float *y, int z)
{
	*x = (*x - *y) * cos(rot->angle);
	*y = (*x + *y) * sin(rot->angle) - z;
}

/* Function for print the pixel in the window */

static void	my_mlx_pixel_put(t_nodes *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.line_length + x
			* (mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* DDA Algorithm Implementation */

static void	dda_line(t_nodes *mlx, float x, float y)
{
	float	x_dist;
	float	y_dist;
	int		steps;

	set_altitude(mlx, (int)x, (int)y);
	set_zoom(mlx, &x, &y);
	convert_isometric(mlx->map, &x, &y, mlx->map->z);
	convert_isometric(mlx->map, &mlx->map->x1, &mlx->map->y1, mlx->map->z1);
	center_image(mlx, &x, &y);
	x_dist = mlx->map->x1 - x;
	y_dist = mlx->map->y1 - y;
	steps = fmax(abs_value(x_dist), abs_value(y_dist));
	x_dist /= steps;
	y_dist /= steps;
	while (steps--)
	{
		set_colors(mlx, steps);
		if (x < MENU || y < 0 || x > WIN_WIDTH || y > WIN_HEIGTH)
			break ;
		my_mlx_pixel_put(mlx, x, y, mlx->rgb.rgb);
		x += x_dist;
		y += y_dist;
	}
}

/* Function to draw the map using the DDA Algorithm */

void	draw(t_nodes *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->map->heigth)
	{
		x = -1;
		while (++x < mlx->map->width)
		{
			mlx->map->x1 = x;
			mlx->map->y1 = y + 1;
			set_color_values(mlx, x, y, 1);
			if (y < mlx->map->heigth - 1)
				dda_line(mlx, x, y);
			mlx->map->x1 = x + 1;
			mlx->map->y1 = y;
			set_color_values(mlx, x, y, 0);
			if (x < mlx->map->width - 1)
				dda_line(mlx, x, y);
		}
	}
}
