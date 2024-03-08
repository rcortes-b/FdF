/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:53 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 15:01:53 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j] && i + j < n)
		{
			if (!to_find[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
