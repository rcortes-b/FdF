/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:17:33 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/17 18:17:34 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_args_printf(char c, va_list args)
{
	int	ret;

	ret = 0;
	if (c == '%')
		ret = ft_putchar_v2('%');
	else if (c == 'c')
		ret = ft_putchar_v2(va_arg(args, int));
	else if (c == 's')
		ret = ft_putstr_v2(va_arg(args, char *));
	else if (c == 'p')
		ret = ft_hex_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ret = ft_itoa_v2(va_arg(args, int));
	else if (c == 'u')
		ret = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x')
		ret = ft_hexadecimal(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ret = ft_hexadecimal(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		res;
	int		tmp;
	va_list	args;

	i = -1;
	res = 0;
	tmp = 0;
	va_start(args, s);
	while (s[++i])
	{
		res++;
		if (s[i] == '%')
		{
			tmp = check_args_printf(s[++i], args);
			if (tmp == -1)
				return (-1);
			res += tmp - 1;
			continue ;
		}
		if (write(1, &s[i], 1) < 0)
			return (-1);
	}
	va_end(args);
	return (res);
}
