/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:19 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/20 17:32:11 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>  //printf
# include <stdlib.h> //malloc
# include <unistd.h> //write

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

char    *get_next_line(int fd);

#endif