/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:09:36 by rcortes-          #+#    #+#             */
/*   Updated: 2024/03/01 14:09:37 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Set the values to get gradient colors */

void	set_color_values(t_nodes *mlx, int x, int y, int is_vertical)
{
	mlx->rgb.rgb = mlx->map->color[(y * mlx->map->width) + x];
	mlx->map->x = x;
	mlx->map->y = y;
	mlx->rgb.color1 = mlx->map->color[(int)(mlx->map->y1
			* mlx->map->width) + (int)mlx->map->x1];
	mlx->rgb.def_color = DEFAULT_COLOR;
	if (is_vertical == 1)
	{
		if (mlx->rgb.rgb == mlx->map->color[((y + 1) * mlx->map->width) + x])
			mlx->rgb.is_diff = 1;
		else
			mlx->rgb.is_diff = 0;
	}
	else
	{
		if (mlx->rgb.rgb == mlx->map->color[(y * mlx->map->width) + (x + 1)])
			mlx->rgb.is_diff = 1;
		else
			mlx->rgb.is_diff = 0;
	}
	mlx->rgb.color1 = mlx->map->color[(int)(mlx->map->y1
			* mlx->map->width) + (int)mlx->map->x1];
}

/* To get the gradient if altitude is not 0 */

static void	gradient_color_altitude(t_nodes *clr, int steps, int def_color)
{
	if (steps == 0)
		return ;
	clr->rgb.r = get_r(def_color);
	clr->rgb.g = get_g(def_color);
	clr->rgb.b = get_b(def_color);
	clr->rgb.diff_r = get_r(0xffffff) - clr->rgb.r;
	clr->rgb.diff_g = get_g(0xffffff) - clr->rgb.g;
	clr->rgb.diff_b = get_b(0xffffff) - clr->rgb.b;
	clr->rgb.r += clr->rgb.diff_r / steps;
	clr->rgb.g += clr->rgb.diff_g / steps;
	clr->rgb.b += clr->rgb.diff_b / steps;
	clr->rgb.rgb = create_rgb(clr->rgb.r, clr->rgb.g, clr->rgb.b);
	clr->rgb.def_color = clr->rgb.rgb;
}

/* To get the gradient if the file passed as map has a color defined */

static void	gradient_color(t_nodes *clr, int steps, int def_color)
{
	if (steps == 0)
		return ;
	clr->rgb.r = get_r(clr->rgb.rgb);
	clr->rgb.g = get_g(clr->rgb.rgb);
	clr->rgb.b = get_b(clr->rgb.rgb);
	clr->rgb.diff_r = get_r(def_color) - clr->rgb.r;
	clr->rgb.diff_g = get_g(def_color) - clr->rgb.g;
	clr->rgb.diff_b = get_b(def_color) - clr->rgb.b;
	clr->rgb.r += clr->rgb.diff_r / steps;
	clr->rgb.g += clr->rgb.diff_g / steps;
	clr->rgb.b += clr->rgb.diff_b / steps;
	clr->rgb.rgb = create_rgb(clr->rgb.r, clr->rgb.g, clr->rgb.b);
}

/* To set the color to put the pixel */

void	set_colors(t_nodes *clr, int steps)
{
	if (clr->map->z == clr->map->z1 && clr->rgb.is_diff)
	{
		if (clr->map->z && clr->map->z1)
			clr->rgb.rgb = DEFAULT_COLOR;
		else
			return ;
	}
	else if (clr->rgb.is_diff)
	{
		if (clr->rgb.color1 == 0xffffff && clr->map->color[(clr->map->y
					* clr->map->width) + clr->map->x] == 0xffffff)
		{
			if ((clr->map->z > clr->map->z1 && clr->map->scale_z >= 0)
				|| (clr->map->z < clr->map->z1 && clr->map->scale_z < 0))
				gradient_color_altitude(clr, steps, clr->rgb.def_color);
			else
				gradient_color(clr, steps, DEFAULT_COLOR);
		}
		else
			return ;
	}
	else
		gradient_color(clr, steps, clr->rgb.color1);
}
