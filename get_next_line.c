/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:01:46 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/10 22:14:37 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	size_t	len;
	char	*line;

	line = "\0";
	len = 0;	
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (buffer[len] == '\n')
			return (line);	
		line = ft_strjoin(line, buffer);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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
	return(0);
}
