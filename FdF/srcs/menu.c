/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:40:45 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/29 16:40:46 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	aux_menu_values(t_nodes *mlx)
{
	char	*angle;
	char	*value;
	int		decimals;

	decimals = (mlx->map->angle * 100);
	if (decimals > 110)
		decimals -= 100;
	angle = ft_itoa(mlx->map->angle);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 370, 0x00ffff,
		"[4] Altitude Scale: ");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 195, 370, 0x00ffff,
		value = ft_itoa(mlx->map->scale_z));
	free(value);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 390, 0x00ffff,
		"[5] Angle Value: ");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 165, 390, 0x00ffff, angle);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 173, 390, 0x00ffff, ".");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 181, 390, 0x00ffff,
		value = ft_itoa(decimals));
	free(value);
	value = NULL;
	free(angle);
	angle = NULL;
}

static void	menu_values(t_nodes *mlx)
{
	char	*value;

	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 310, 0x00ffff,
		"[1] Zoom Value: ");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 160, 310, 0x00ffff,
		value = ft_itoa(mlx->map->zoom));
	free(value);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 330, 0x00ffff,
		"[2] X Position: ");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 160, 330, 0x00ffff,
		value = ft_itoa(mlx->map->shift_x));
	free(value);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 350, 0x00ffff,
		"[3] Y Position: ");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 160, 350, 0x00ffff,
		value = ft_itoa(mlx->map->shift_y));
	free(value);
	value = NULL;
	aux_menu_values(mlx);
}

static void	menu_controls(t_nodes *mlx)
{
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 70, 0x00ffff,
		"[1] Press '+' to zoom in");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 90, 0x00ffff,
		"[2] Press '-' to zoom out");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 110, 0x00ffff,
		"[3] Press '->' to move right");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 130, 0x00ffff,
		"[4] Press '<-' to move left");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 150, 0x00ffff,
		"[5] Press '^' to move up");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 110, 156, 0x00ffff, "'");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 110, 170, 0x00ffff, "'");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 170, 0x00ffff,
		"[6] Press 'v' to move down");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 190, 0x00ffff,
		"[7] Press '1' to rotate right");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 210, 0x00ffff,
		"[8] Press '2' to rotate left");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 230, 0x00ffff,
		"[9] Press '4' to decrease altitude");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 0, 250, 0x00ffff,
		"[10] Press '5' to increase altitude");
}

void	menu(t_nodes *mlx)
{
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 100, 10, 0xffffff, "MENU");
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 5, 40, 0xff0000, "Controls");
	menu_controls(mlx);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 5, 280, 0xff0000, "Values");
	menu_values(mlx);
	mlx_string_put(mlx->win.mlx, mlx->win.mlx_win, 45, 450, 0x52f49f,
		"Thank you =)");
}
