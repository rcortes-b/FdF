/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:40 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/27 15:59:41 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_win_values(t_nodes *mlx)
{
	int	set_width;
	int	set_heigth;

	set_width = (WIN_WIDTH - MENU) / mlx->map->width / 1.8;
	set_heigth = WIN_HEIGTH / mlx->map->heigth / 1.8;
	mlx->map->zoom = fmin(set_width, set_heigth);
	mlx->map->shift_x = (WIN_WIDTH - MENU) / 3 + MENU;
	mlx->map->shift_y = WIN_HEIGTH / 3;
	mlx->map->angle = 0.6;
	mlx->map->scale_z = 1;
}

void	set_zoom(t_nodes *mlx, float *x, float *y)
{
	*x *= mlx->map->zoom;
	*y *= mlx->map->zoom;
	mlx->map->x1 *= mlx->map->zoom;
	mlx->map->y1 *= mlx->map->zoom;
}

void	center_image(t_nodes *mlx, float *x, float *y)
{
	*x += mlx->map->shift_x;
	*y += mlx->map->shift_y;
	mlx->map->x1 += mlx->map->shift_x;
	mlx->map->y1 += mlx->map->shift_y;
}
