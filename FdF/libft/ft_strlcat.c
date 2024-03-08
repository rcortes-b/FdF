/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:03:55 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 15:03:56 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	res;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	res = 0;
	if (dest_len < size)
		res = dest_len + src_len;
	else
		res = src_len + size;
	i = 0;
	while (src[i] != '\0' && (dest_len + 1) < size)
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	return (res);
}
