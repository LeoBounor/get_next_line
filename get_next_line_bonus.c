/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:44:23 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/25 11:45:47 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fill_buffer(int fd, char *buffer)
{
	int		readfd;
	char	str[BUFFER_SIZE + 1];

	readfd = 1;
	while (!ft_strchr(buffer, '\n') && readfd != 0)
	{
		readfd = read(fd, str, BUFFER_SIZE);
		if (readfd < 0)
			return (NULL);
		str[readfd] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_move_buffer(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = malloc(sizeof(char) * (ft_strlen(buffer) - (i)) + 1);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;
	size_t		i;

	i = 0;
	if (fd > OPEN_MAX || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer[fd] = ft_fill_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (!*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_move_buffer(buffer[fd]);
	return (line);
}
