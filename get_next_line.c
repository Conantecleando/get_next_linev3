/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:24:58 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/26 02:58:24 by daroldan         ###   ########.fr       */
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
	p = malloc (sizeof(char) * ((ft_strlen(s1))
				+ (ft_strlen(s2)) + 1));
	if (!p)
		return (0);
	while (s1[cont] != 0)
	{
		p[cont] = s1[cont];
		cont++;
	}
	while (s2[cont2] != 0)
	{
		p[cont + cont2] = s2[cont2];
		cont2++;
	}
	p[(ft_strlen(s1) + ft_strlen(s2))] = '\0';
	return (p);
}

char	*ft_joinfree(char *str, char *str2)
{
	char	*s3;

	if (!str)
	{
		str = malloc ((sizeof(char)));
		str[0] = '\0';
		if (!str)
			free (str);
	}
	s3 = ft_strjoin(str, str2);
	s3[ft_strlen(s3) + 1] = '\0';
	free (str);
	return (s3);
}

char	*readsave(int fd, char	*strold)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		posstr;
	char		*heap;

	posstr = 1;
	heap = NULL;
	heap = ft_strdup(strold);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (posstr > 0)
	{	
		posstr = read(fd, buffer, BUFFER_SIZE);
		if (posstr < 0)
			return (NULL);
		else if (posstr == 0)
			return (heap);
		if (posstr < BUFFER_SIZE)
			return (ft_joinfree(heap, buffer));
		heap = ft_joinfree(heap, buffer);
		heap[ft_strlen(heap) + 1] = '\0';
		if (ft_strchr(heap, '\n'))
			break ;
	}
	return (heap);
}

char	*ft_get_line(char	*buffer)
{
	size_t		pos;
	char		*line;

	pos = 0;
	if (!buffer[pos])
		return (NULL);
	while (buffer[pos - 1] != '\n' && buffer[pos])
		pos++;
	line = malloc((sizeof(char)) * (pos + 1));
	if (!line)
		return (NULL);
	pos = 0;
	while (buffer[pos - 1] != '\n' && buffer[pos])
	{
		line[pos] = buffer[pos];
		pos++;
	}
	line[pos + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*strstatic;
	size_t			len;
	char			*buffer;	
	char			*print;

	buffer = malloc ((sizeof (char)) * (15 + 1));
	if ((fd <= 0) || (BUFFER_SIZE < 1))
		return (free(buffer), NULL);
	buffer = readsave(fd, strstatic);
	if (!buffer)
		return (free(buffer), NULL);
	len = ft_strlen(buffer);
	buffer[len + 1] = '\0';
	strstatic = ft_strrchr(buffer, '\n');
	print = malloc ((sizeof(char)) * (ft_strlen(buffer) + 1));
	print = ft_get_line(buffer);
	free(buffer);
	return (print);
}
