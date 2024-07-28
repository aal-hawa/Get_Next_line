/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:01:00 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/28 15:23:25 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE = 1024
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup_line(const char *str);
size_t	ft_strlen_line(const char *s);
char	*ft_strdup_after_line(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);


#endif