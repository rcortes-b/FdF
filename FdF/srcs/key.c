/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:32:19 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/29 18:32:21 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
KEYCODE LIST
zoom -> + (69)
zoom -> - (78)
shiftup ^ (126)
shiftright --> (124)
shiftleft <-- (123)
shiftdown (125)
Rotate left 1 (83)
Rotate right 2 (84)
Altitude plus 3 (86)
Altitude minus 4 (87)
*/

static void	do_image(t_nodes *mlx)
{
	free(mlx->img.img);
	free(mlx->img.addr);
	mlx->img.img = mlx_new_image(mlx->win.mlx, WIN_WIDTH, WIN_HEIGTH);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
}

static int	aux_key_exe(int keycode, t_nodes *mlx)
{
	if (keycode == 86)
	{
		if (mlx->map->scale_z == -1)
			mlx->map->scale_z += 2;
		else
			mlx->map->scale_z += 1;
	}
	else if (keycode == 87)
	{
		if (mlx->map->scale_z == 1)
			mlx->map->scale_z -= 2;
		else
			mlx->map->scale_z -= 1;
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->win.mlx, mlx->win.mlx_win);
		free_mem(&mlx->map);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	key_exe(int keycode, t_nodes *mlx)
{
	if (keycode == 69)
		mlx->map->zoom += 2;
	else if (keycode == 78)
		mlx->map->zoom -= 2;
	else if (keycode == 124)
		mlx->map->shift_x += 10;
	else if (keycode == 123)
		mlx->map->shift_x -= 10;
	else if (keycode == 126)
		mlx->map->shift_y -= 10;
	else if (keycode == 125)
		mlx->map->shift_y += 10;
	else if (keycode == 83)
		mlx->map->angle -= 0.1;
	else if (keycode == 84)
		mlx->map->angle += 0.1;
	aux_key_exe(keycode, mlx);
	do_image(mlx);
	draw(mlx);
	mlx_put_image_to_window(mlx->win.mlx, mlx->win.mlx_win, mlx->img.img, 0, 0);
	menu(mlx);
	return (0);
}
