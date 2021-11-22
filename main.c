/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:09:18 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/22 12:44:02 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

int	main()
{
    int fd;
    fd = open("gnlTester/files/42_with_nl", O_RDWR);
    // fd = 1000;
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
    printf("%s\n", c);
    return 0;
}

// int main(void)
// {
//     char    *str;
//     int     fd;

//     str = NULL;
//     fd = open("test.txt", O_RDWR);
//     str = ft_get_line(fd);
//     while(str)
//     {
//         printf("%s", str);
//         free(str);
//         str = ft_get_line(fd);
//     }
// }