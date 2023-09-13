/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:24:58 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/14 01:27:34 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		cont;
	int		cont2;

	cont = 0;
	cont2 = 0;
	p = malloc (sizeof(char) * ((ft_strlen(s1)
					+ ft_strlen(s2)) + 1));
	if (!p)
	{
		free (p);
		return (0);
	}
	while (s1 != 0 && cont < (int)ft_strlen(s1))
	{
		p[cont] = s1[cont];
		cont++;
	}
	while (s2 != 0 && cont2 < (int)ft_strlen(s2))
	{
		p[cont + cont2] = s2[cont2];
		cont2++;
	}
	p[cont + cont2] = '\0';
	return (p);
}

char	*ft_joinfree(char *str, char *str2)
{
	char	*s3;

	if (!str)
		str = (char *)ft_calloc(1, 1);
	if (!str2)
		str2 = (char *)ft_calloc(1, 1);
	s3 = ft_strjoin(str, str2);
	return (s3);
}

char	*readsave(int fd, char	*strold)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		posstr;
	char		*heap;
	char		*line;

	heap = strold;
	posstr = 1;
	while (posstr > 0)
	{	
		posstr = read(fd, buffer, BUFFER_SIZE);
		heap = ft_joinfree(heap, buffer);
		heap[ft_strlen(heap) + 1] = '\0';
		line = malloc ((sizeof(char)) * (ft_strlen(heap) + 1));
		line = ft_strchr(heap, '\n');
		if (line)
			break ;
	}
	return (heap);
}

char	*get_line(char	*buffer)
{
	size_t		pos;
	char		*line;

	pos = 0;
	if (!buffer[pos])
		return (NULL);
	while (buffer[pos] != '\n' && buffer[pos])
		pos++;
	line = malloc((sizeof(char)) * (pos +2));
	if (!line)
		return (free(line), NULL);
	pos = 0;
	while (buffer[pos] != '\n' && buffer[pos])
	{
		line[pos] = buffer[pos];
		pos++;
	}
	line[pos + 1] = '\n';
	line[pos + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*strstatic = NULL;
	size_t			len;
	char			*buffer;	
	char			*print;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	buffer = readsave(fd, strstatic);
	len = ft_strlen(buffer);
	buffer[len + 1] = '\0';
	strstatic = ft_strrchr(buffer, '\n');
	print = get_line(buffer);
	return (print);
}