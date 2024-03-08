/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:15:12 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/26 19:15:14 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	close_win_mouse(t_nodes *mlx)
{
	mlx_destroy_window(mlx->win.mlx, mlx->win.mlx_win);
	free_mem(&mlx->map);
	exit(EXIT_FAILURE);
	return (0);
}

int	main(int argc, char **argv)
{
	t_nodes	mlx;

	if (argc != 2)
		return ((0));
	mlx.map = malloc(sizeof(t_nodes));
	if (!mlx.map)
		return (0);
	read_coords(&mlx.map, argv[1]);
	mlx.rgb.rgb = mlx.map->color[0];
	set_win_values(&mlx);
	mlx.win.mlx = mlx_init();
	mlx.win.mlx_win = mlx_new_window(mlx.win.mlx, WIN_WIDTH, WIN_HEIGTH, "FdF");
	mlx.img.img = mlx_new_image(mlx.win.mlx, WIN_WIDTH, WIN_HEIGTH);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	draw(&mlx);
	mlx_put_image_to_window(mlx.win.mlx, mlx.win.mlx_win, mlx.img.img, 0, 0);
	menu(&mlx);
	mlx_key_hook(mlx.win.mlx_win, key_exe, &mlx);
	mlx_hook(mlx.win.mlx_win, 17, 0, close_win_mouse, &mlx);
	mlx_loop(mlx.win.mlx);
}
