/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:00:07 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/29 15:00:28 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*write_toline(char *text_buffer)
// {
//     char *buffer_return;
    
//     buffer_return = ft_strdup_line(text_buffer);
//     text_buffer = ft_strdup_after_line(text_buffer);
// 	return (buffer_return);
// }

char	*get_next_line(int fd)
{
    ssize_t			bytesreed;
    static char		*text_buffer;
    char			*returntext;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!text_buffer)
	{
		text_buffer = malloc(sizeof(char));
		if (!text_buffer)
			return (NULL);
		text_buffer[0] = '\0';
	}
	returntext = malloc(sizeof(char) * BUFFER_SIZE);
	if (!returntext)
		return (NULL);
	bytesreed = read(fd, returntext, BUFFER_SIZE);
	// printf("%ld\n", bytesreed);
	// if (bytesreed < 0)
	// {
	// 	if (text_buffer)
	// 	{
	// 		free(text_buffer);
	// 		text_buffer = NULL;
	// 		free(returntext);
	// 		returntext = NULL;
	// 	}
	// 	return (NULL);
	// }
	if (bytesreed > 0)
    {
    	returntext[bytesreed] = '\0';
		text_buffer = ft_strjoin(text_buffer, returntext);
		free(returntext);
		returntext = NULL;
		returntext = ft_strdup_line(text_buffer);
    	text_buffer = ft_strdup_after_line(text_buffer);
    }
	else if(text_buffer[0])
	{
		free(returntext);
		returntext = NULL;
		returntext = ft_strdup_line(text_buffer);
    	text_buffer = ft_strdup_after_line(text_buffer);
	}
	else
	{
		free(text_buffer);
		text_buffer = NULL;
		free(returntext);
		returntext = NULL;

		// return (NULL);
	}
	
    return (returntext);
}