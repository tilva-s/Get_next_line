/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:01:46 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/11 17:41:11 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	ssize_t	count;
	char	*line;

	line = "\0";
	count = 0;	
	while (1)
	{
		if (buffer[0] == '\0')
		{
			count = read(fd, buffer, BUFFER_SIZE);
			if (count == -1)
				return (NULL);
			if (count == 0)
				return (line);
		}
		line = ft_strjoin(line, buffer);
		buffer_clear(buffer);
		if (check_n(line))
			break;
	}
	return (line);
}
/*
int	main()
{
	int	fd;
	char	*line;
	
	line = NULL;
	fd = open("txt.txt", O_RDONLY);

	if (fd == -1)
		printf("Erro main");
	else
		line = get_next_line(fd);
	printf("%s", line);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
	return(0);
}*/
