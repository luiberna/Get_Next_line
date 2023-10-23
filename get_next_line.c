/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:50 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/23 15:39:46 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	str = NULL;
	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
        return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_makeline(str, buffer);
        clean_buffer(buffer);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
/* 
int	main(void)
{
	int fd;
	char *line;
    int nblines = 0;

	fd = open("teste.txt", O_RDONLY);
    while (nblines < 2)
	{
        line = get_next_line(fd);
    	printf("%s", line);
        nblines++;
    }
} */