/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:17:43 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/17 18:17:44 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_long_size(unsigned long int nb)
{
	size_t	count;

	count = 0;
	while (nb >= 0)
	{
		nb /= 16;
		count++;
		if (nb == 0)
			break ;
	}
	return (count);
}

static size_t	check_size(unsigned int nb)
{
	size_t	count;

	count = 0;
	while (nb >= 0)
	{
		nb /= 16;
		count++;
		if (nb == 0)
			break ;
	}
	return (count);
}

int	ft_hexadecimal(unsigned int nb, char const *format)
{
	size_t			n_size;
	unsigned int	tmp;
	char			*nmbr;

	tmp = nb;
	n_size = check_size(nb);
	nmbr = (char *)malloc(sizeof(char) * n_size + 1);
	if (!nmbr)
		return (-1);
	nmbr[n_size] = '\0';
	while (nb >= 0)
	{
		nmbr[--n_size] = format[nb % 16];
		nb /= 16;
		if (nb == 0)
			break ;
	}
	n_size = ft_putstr_v2(nmbr);
	free(nmbr);
	return ((int)n_size);
}

int	ft_ulong_hexadecimal(unsigned long int nb, char const *format)
{
	size_t				n_size;
	unsigned long int	tmp;
	char				*nmbr;

	tmp = nb;
	n_size = check_long_size(nb);
	nmbr = (char *)malloc(sizeof(char) * n_size + 1);
	if (!nmbr)
		return (-1);
	nmbr[n_size] = '\0';
	while (nb >= 0)
	{
		nmbr[--n_size] = format[nb % 16];
		nb /= 16;
		if (nb == 0)
			break ;
	}
	n_size = ft_putstr_v2(nmbr);
	free(nmbr);
	return ((int)n_size);
}

int	ft_hex_pointer(void *ptr)
{
	int	ret;

	ret = 2;
	if (write(1, "0x", 2) < 0)
		return (-1);
	ret += ft_ulong_hexadecimal((unsigned long)ptr, "0123456789abcdef");
	if (ret == 1)
		return (-1);
	return (ret);
}
