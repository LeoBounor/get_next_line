/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:41:45 by Leo               #+#    #+#             */
/*   Updated: 2021/11/16 22:14:38 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fillbuffer(int fd, char *buffer)
{
	int		readfd;
	char	*str;

	redfd = 1;
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && readfd != 0)
	{
		readfd = read(fd, str, BUFFER_SIZE);
		if (readfd == -1)
		{
			free(str)
			return (NULL);
		}
		str[readfd] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*ft_get_line(char *line, char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_fill_buffer(fd, buffer);
	line = ft_get_line(line, buffer);
}
