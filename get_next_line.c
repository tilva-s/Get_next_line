/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:13:05 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/18 14:58:47 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		retorno;

	if (check_problems(fd, buffer))
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			retorno = read(fd, buffer, BUFFER_SIZE);
			if (retorno < 0)
			{
				free (line);
				return (NULL);
			}
			if (retorno == 0)
				return (line);
		}
		line = ft_strjoin(line, buffer);
		if (buffer_clear(buffer) == 1)
			break ;
	}
	return (line);
}
/*int main()
{
    int fd;
    int i;
    char *line;
    fd = open("txt.txt", O_RDONLY);

    i = 1;
    while (1)
    {
        line = get_next_line(fd);
        printf("%d %s", i, line);
        if (!line)
        {
            free(line);
            break ;
        }
        i++;
        free(line);
    }
    return 0;
}*/
