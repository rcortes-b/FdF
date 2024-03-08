/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:58:06 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/28 12:58:08 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_mem(t_map **map)
{
	int	y;

	y = -1;
	while (++y < (*map)->heigth)
		free((*map)->coord[y]);
	free((*map)->coord);
	free((*map)->color);
	free(*map);
}

void	handle_error(t_map **map)
{
	int	i;

	i = -1;
	if ((*map)->coord)
	{
		while ((*map)->coord[++i])
			free((*map)->coord[i]);
		free((*map)->coord);
	}
	if ((*map)->color)
		free((*map)->color);
	free(*map);
	exit(EXIT_FAILURE);
}

int	abs_value(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}
