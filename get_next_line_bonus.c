/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:53:26 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/17 19:29:26 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		retorno;

	if (check_problems(fd, buffer[fd]))
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			retorno = read(fd, buffer[fd], BUFFER_SIZE);
			if (retorno < 0)
			{
				free (line);
				return (NULL);
			}
			if (retorno == 0)
				return (line);
		}
		line = ft_strjoin(line, buffer[fd]);
		if (buffer_clear(buffer[fd]) == 1)
			break ;
	}
	return (line);
}
