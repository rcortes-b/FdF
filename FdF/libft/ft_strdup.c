/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:09 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 15:01:10 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = s[i];
	str[size] = '\0';
	return (str);
}
