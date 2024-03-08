/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:02:14 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/27 20:45:46 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_alloc(size_t i, size_t size, char const *str, char const *set)
{
	int	count;

	count = 0;
	if (size == 0)
	{
		while (check_char(str[i], set) != 0)
		{
			count++;
			i++;
		}
	}
	else
	{
		while (check_char(str[--size], set) != 0)
			count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		size;
	int		end;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	start = get_alloc(0, 0, s1, set);
	end = get_alloc(0, size, s1, set);
	if (start + end > size)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * size - start - end + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, &((char *)s1)[start], size - start - end);
	str[size - start - end] = '\0';
	return (str);
}
