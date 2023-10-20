/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:50 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/20 17:31:30 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
#include <fcntl.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    if (!str)
        return (0);
    while (str [len] && str[len] != '\n')
        len++;
    if (str[len] == '\n')
        len++;
    return (len);
}


char *ft_makeline(char *str, char *buffer)
{
    int i;
    int j;
    char *line;

    i = 0;
    j = 0;
    
    line = malloc(ft_strlen(buffer) + ft_strlen(str) + 1);
    if (!line)
        return (NULL);
    if(str != NULL)
    {
        while (str[i])
        {
            line[i] = str[i];
            i++;
        }
    }
    while (buffer[j] && buffer[j] != '\n')
    { 
        line[i] = buffer[j];
        j++;
        i++;
    }
    if (buffer[j] == '\n')
        line[i++] = '\n';
    free (str);
    line[i] = '\0';
    return (line);
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *str;
    int i;

    str = NULL;
    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        while (i <= BUFFER_SIZE)
        {
            buffer[i] = 0;
            i++;
        }
    }
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        str = ft_makeline(str, buffer);
        if (str[ft_strlen(str) - 1] == '\n')
            return (str);
    }
    return (str);
}

int main(void)
{   
    int fd;
    char *line;
    
    fd = open("teste.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
}