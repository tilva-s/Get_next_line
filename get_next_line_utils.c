/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:10:37 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/11 17:11:20 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_n(char *line)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	buffer_clear(char *ptr)
{
	size_t	i;
	size_t 	j;
	size_t	lenbuff;
	
	i = 0;
	j = 0;
	lenbuff = ft_strlen(ptr);
	while (ptr[i] != '\n' && i < lenbuff)
	{
		ptr[i] = '\0';
		i++;
	}
	if (ptr[i] == '\n')
	{
		while (i < lenbuff)
		{
			ptr[j] = ptr[i + 1];
			j++;
			i++; 
		}
	}
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
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
			ptr[i] = s2[j];
	else
		ptr[i] = '\0';
	if (!s1)
		free((void *)s1);
	return (ptr);
}
