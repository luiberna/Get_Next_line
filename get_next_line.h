/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:19 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/25 17:06:09 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>  //fd control options
# include <stdio.h>  //printf
# include <stdlib.h> //malloc
# include <unistd.h> //write

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999999
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_makeline(char *str, char *buffer);
void	clean_buffer(char *buffer);

#endif