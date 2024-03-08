/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:02:00 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 15:02:01 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (s[size] == (char)c)
		return (&((char *)s)[size]);
	while ((int)--size >= 0)
	{
		if (s[size] == (char)c)
			return (&((char *)s)[size]);
	}
	return (NULL);
}
