/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:00:53 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/07/29 20:19:12 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	if (!dst)
		return (NULL);
	while (s1[i])
		dst[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	free_char(s1);
	return (dst);
}

char	*ft_strdup_line(char *str, int eof)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	while (str[i] && str[i] != '\n' && eof == 1)
		i++;
	if (!str[i] && eof == 1)
		return (NULL);

	len = ft_strlen_line(str);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_after_line(char *str)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - ft_strlen_line(str);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	while (str[i])
	{
		dst[j] = str[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	free_char(str);

	return (dst);
}


