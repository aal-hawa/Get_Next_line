/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:00:07 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/29 20:19:51 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_char(char *this_string)
{
	if(!this_string)
		return (NULL);
	free(this_string);
	this_string = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
    ssize_t			bytesreed;
    static char		*text_buffer;
    char			*returntext;

	if (fd < 0 || BUFFER_SIZE <= 0 )
	{
		// text_buffer = free_char(text_buffer);
		return (NULL);
	}
	if (!text_buffer)
	{
		text_buffer = malloc(sizeof(char) * 1);
		if (!text_buffer)
			return (NULL);
		text_buffer[0] = '\0';
	}
	
	bytesreed = 1;
	while (bytesreed > 0)
	{
		returntext = malloc(sizeof(char) * BUFFER_SIZE);
		if (!returntext)
		{
			text_buffer = free_char(text_buffer);
			return (NULL);
		}
		bytesreed = read(fd, returntext, BUFFER_SIZE);
		if (bytesreed > 0)
	    {
	    	returntext[bytesreed] = '\0';
			text_buffer = ft_strjoin(text_buffer, returntext);
			returntext = free_char(returntext);
			returntext = ft_strdup_line(text_buffer, 1);
			if (returntext)
			{
	    		text_buffer = ft_strdup_after_line(text_buffer);
				break;
			}
	    }
		else if(bytesreed == 0 && text_buffer[0])
		{
			returntext = free_char(returntext);
			returntext = ft_strdup_line(text_buffer, 0);
	    	text_buffer = ft_strdup_after_line(text_buffer);
			if (!text_buffer[0])
				text_buffer = free_char(text_buffer);
			break;
		}
		else
		{
			text_buffer = free_char(text_buffer);
			returntext = free_char(returntext);
		
			return (NULL);

		}
	}
    return (returntext);
}