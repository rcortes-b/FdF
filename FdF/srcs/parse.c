/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:51:07 by rcortes-          #+#    #+#             */
/*   Updated: 2024/02/25 18:51:10 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Function for save lines */

static	void	alloc_memory(t_map **coord)
{
	(*coord)->coord = (int **)malloc(sizeof(int *) * ((*coord)->heigth + 1));
	if (!(*coord)->coord)
		handle_error(coord);
	(*coord)->color = malloc(sizeof(int)
			* ((*coord)->width * (*coord)->heigth + 1));
	if (!(*coord)->color)
		handle_error(coord);
}

/* This function converts the hexadecimal color from the file to int */

static int	parse_color(char *color)
{
	int	num;
	int	i;

	num = 0;
	i = 2;
	while (color[i])
	{
		num *= 16;
		if (ft_isdigit(color[i]))
			num += (color[i] - '0');
		else
			num += (color[i] - 'A' + 10);
		i++;
	}
	return (num);
}

/* This function calculate the width and the heigth */

static void	get_max_values(t_map **coord, char *argv)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	(*coord)->x = -1;
	(*coord)->y = 0;
	while (split[++(*coord)->x])
		free(split[(*coord)->x]);
	free(split);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*coord)->y++;
	}
	free(line);
	(*coord)->width = (*coord)->x;
	(*coord)->heigth = (*coord)->y;
	close(fd);
}

/* Get the data (altitude && color) from the file */

static void	parse_line(t_map **crd, char *line, int y)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(line, ' ');
	i = -1;
	while (split[++i])
	{
		(*crd)->coord[y][i] = ft_atoi(split[i]);
		(*crd)->color[(y * (*crd)->width) + i] = 16777215;
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == ',')
				(*crd)->color[(y *(*crd)->heigth)
					+ i] = parse_color(&split[i][++j]);
		}
		free(split[i]);
	}
	(*crd)->coord[y][i] = 0;
	free(split);
}

/* Main "read file" function */

void	read_coords(t_map **coord, char *argv)
{
	int		y;
	int		fd;
	char	*line;

	get_max_values(coord, argv);
	alloc_memory(coord);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	y = -1;
	while (line)
	{
		(*coord)->coord[++y] = malloc(sizeof(int) * ((*coord)->width + 1));
		if (!(*coord)->coord[y])
			handle_error(coord);
		parse_line(coord, line, y);
		free(line);
		line = get_next_line(fd);
	}
	(*coord)->coord[++y] = 0;
	(*coord)->color[(*coord)->width * (*coord)->heigth] = 0;
	free(line);
	close(fd);
}
