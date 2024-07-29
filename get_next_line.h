/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:01:00 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/29 19:40:26 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_line(const char *s);
char	*ft_strdup_line(char *str, int eof);
char	*ft_strdup_after_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_char(char *this_string);


#endif