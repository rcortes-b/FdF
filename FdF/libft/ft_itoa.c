/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:49:26 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 14:49:32 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_size(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		n++;
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*get_nums(char *str, int size, int n)
{
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		str[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = get_str_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[size] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
		str[0] = '-';
	str = get_nums(str, size, n);
	str[size] = '\0';
	return (str);
}
