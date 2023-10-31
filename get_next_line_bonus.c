/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:50 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/25 17:24:39 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	str = NULL;
	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
	{
		while (fd > 0 && fd < MAX_FD && i <= BUFFER_SIZE)
		{
			buffer[fd][i] = '\0';
			i++;
		}
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_makeline(str, buffer[fd]);
		clean_buffer(buffer[fd]);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		nbl;

	nbl = 0;
	fd = (void *)NULL;//open("teste.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
while (1)
{
	if (!line)
		break ;
	nbl++;
}
}
 */