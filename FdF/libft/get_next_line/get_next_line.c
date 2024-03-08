/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:33:31 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/19 14:33:32 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *str, int fd);
static char	*get_line(char *str);
static char	*store_next(char *str);

static char	*get_freed(char *str, char *buff)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	str[fd] = read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = store_next(str[fd]);
	return (line);
}

static char	*read_line(char *str, int fd)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff && str)
		return (get_freed(str, NULL));
	else if (!buff)
		return (NULL);
	bytes = 1;
	while ((!ft_strchr_v2(str, '\n')) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (get_freed(str, buff));
		buff[bytes] = '\0';
		str = ft_strjoin_v2(str, buff);
		if (!str)
			return (get_freed(buff, NULL));
	}
	free(buff);
	buff = NULL;
	return (str);
}

static char	*get_line(char *str)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		line = (char *)malloc(sizeof(char) * (len + 2));
	else
		line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = str[i];
	if (str[len] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*store_next(char *str)
{
	int		len;
	char	*store;
	int		i;

	len = 0;
	store = NULL;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		len++;
	store = (char *)malloc(sizeof(char) * (ft_strlen_v3(&str[len]) + 1));
	if (!store)
		return (get_freed(str, NULL));
	i = 0;
	while (str[len] != '\0')
		store[i++] = str[len++];
	store[i] = '\0';
	free(str);
	str = NULL;
	return (store);
}
