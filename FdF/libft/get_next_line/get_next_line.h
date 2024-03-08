/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:33:37 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/19 14:33:38 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

//Aux
size_t	ft_strlen_v3(char const *str);
char	*ft_strchr_v2(const char *s, int c);
char	*ft_strjoin_v2(char *s1, char *s2);
//Main Functions
char	*get_next_line(int fd);
#endif
