/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:25:13 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/18 15:01:40 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (line_cut(ptr));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0); 
	else
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char	*line_cut(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i + 1] = '\0';
		i++;
	}
	return (line);
}

ssize_t	buffer_clear(char *buffer)
{
	size_t	i;
	size_t	j;
	ssize_t	result;
	size_t	len;

	result = 0;
	i = 0;
	j = 0;
	len = ft_strlen(buffer);
	while (i < len)
	{
		if (buffer[i] == '\n' || result == 1)
		{
			result = 1;
			buffer[j] = buffer[i + 1];
			buffer[i + 1] = '\0';
			j++;
		}
		else
			buffer[i] = '\0';
		i++;
	}
	return (result);
}

int	check_problems(int fd, char *buffer)
{
	size_t	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (i < BUFFER_SIZE)
			{
				buffer[i] = '\0';
				i++;
			}
		}
		return (1);
	}
	return (0);
}
