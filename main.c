/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:09:18 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/18 13:09:56 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

int	main()
{
    int fd = open("test.txt", O_RDWR);
    int i = 1;
    char *c = NULL;

    while (i)
    {
        c = get_next_line(fd);
        if (!c)
            i--;
        else
            ft_putstr(c);
        free(c);
    }
    return 0;
}
