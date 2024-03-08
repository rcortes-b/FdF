/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:02:05 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 15:02:06 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;
	int		tmp;

	i = -1;
	tmp = 0;
	count = 0;
	if (!ft_strlen(str))
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
		{
			if (tmp)
			{
				count++;
				tmp = 0;
			}
		}
		else
			tmp = 1;
	}
	if (str[i - 1] != c)
		count++;
	return (count);
}

static int	next_word(char const *str, size_t *i, char c)
{
	size_t	size;

	while (str[*i] && str[*i] == c)
		*i += 1;
	size = 0;
	while (str[*i + size] && str[*i + size] != c)
		size++;
	return (size);
}

static void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;
	size_t	words_count;
	size_t	word_size;
	size_t	i;

	words = count_words(s, c);
	strs = ft_calloc(sizeof (char *), words + 1);
	if (!strs)
		return (NULL);
	i = 0;
	words_count = 0;
	while (words_count < words)
	{
		word_size = next_word(s, &i, c);
		strs[words_count] = ft_calloc(sizeof (char), word_size + 1);
		if (!strs[words_count])
		{
			free_all(strs);
			return (NULL);
		}
		ft_strlcpy(strs[words_count++], &s[i], word_size + 1);
		i += word_size;
	}
	return (strs);
}
