/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:17:38 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/17 18:17:39 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_v2(char c)
{
	if (write(1, &c, 1) != -1)
		return (1);
	return (-1);
}

int	ft_putstr_v2(char *str)
{
	int	size;

	if (!str)
	{
		size = ft_putstr_v2("(null)");
		return (size);
	}
	size = 0;
	while (str[size])
	{
		if (write(1, &str[size], 1) < 0)
			return (-1);
		size++;
	}
	return (size);
}
