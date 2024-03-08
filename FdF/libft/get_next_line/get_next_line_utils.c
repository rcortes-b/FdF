/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:33:44 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/19 14:33:45 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_v3(char const *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_v2(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_v2(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = ft_strlen_v3(s1);
	str = (char *)malloc(sizeof(char) * (s1_len + ft_strlen_v3(s2) + 1));
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
