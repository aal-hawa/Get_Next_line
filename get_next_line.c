/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:00:07 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/28 15:26:22 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_toline(char *text_buffer)
{
    char *buffer_return;
    
    buffer_return = ft_strdup_line(text_buffer);
    text_buffer = ft_strdup_after_line(text_buffer);
	return (buffer_return);
}

char	*get_next_line(int fd)
{
    ssize_t			bytesreed;
    static char		*text_buffer;
    char			*returntext;
	
	if (!text_buffer)
	{
		text_buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (!text_buffer)
			return (NULL);
	}
	returntext = malloc(sizeof(char) * BUFFER_SIZE);
		if (!returntext)
			return (NULL);
	if (bytesreed = read(fd, returntext, BUFFER_SIZE) > 0)
    {
    	returntext[bytesreed] = '\0';
		text_buffer = ft_strjoin(text_buffer, returntext);
    	returntext = write_toline(text_buffer);
    }
    return (returntext);
}