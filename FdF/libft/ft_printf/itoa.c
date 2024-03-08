/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:17:26 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/17 18:17:27 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_itoa_v2(int n)
{
	char	*str;
	size_t	size;

	size = get_str_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (-1);
	if (n == 0)
	{
		str[0] = '0';
		str[size] = '\0';
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
	size = ft_putstr_v2(str);
	free(str);
	return (size);
}

int	ft_uitoa(unsigned int n)
{
	int				count;
	unsigned int	tmp;
	char			*str;

	if (n == 0)
		return (count = ft_putstr_v2("0"));
	tmp = n;
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (-1);
	str[count] = '\0';
	while (tmp > 0)
	{
		str[--count] = (tmp % 10) + '0';
		tmp /= 10;
	}
	count = ft_putstr_v2(str);
	free(str);
	return (count);
}
