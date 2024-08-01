/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:42:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/08/01 20:59:52 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD OPEN_MAX
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_line(const char *s);
char	*ft_strdup_line(char *str, int eof);
char	*ft_strdup_after_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_char(char *this_string);

#endif