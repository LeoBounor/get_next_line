/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:42:54 by Leo               #+#    #+#             */
/*   Updated: 2021/11/22 13:56:45 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd);
char	*ft_fill_buffer(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_move_buffer(char *buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif