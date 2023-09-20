/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:24:58 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/20 21:06:33 by daroldan         ###   ########.fr       */
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
	p = malloc (sizeof(char) * ((ft_strlen(s1) + 1)
				+ (ft_strlen(s2)+ 1)));
	if (!p)
		return (0);
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
	p[(cont + cont2) + 1] = '\0';
	return (p);
}

char	*ft_joinfree(char *str, char *str2)
{
	char	*s3;

	if (!str)
	{
		str = malloc ((sizeof(char)) + 1);
		str[ft_strlen(str) + 1] = '\0';
	}
	if (!str2)
	{
		str2 = malloc ((sizeof(char)) + 1);
		str[ft_strlen(str2) + 1] = '\0';
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
	heap = ft_joinfree(heap, strold);
	while (posstr > 0)
	{	
		posstr = read(fd, buffer, BUFFER_SIZE);
		if (posstr < 0)
			return (free(heap), NULL);
		else if (posstr == 0)
			return (heap);
		else if (posstr < BUFFER_SIZE)
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
		return (free(buffer), NULL);
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

	if ((fd <= 0) || (BUFFER_SIZE < 1))
		return (NULL);
	buffer = malloc ((sizeof (char)) * (BUFFER_SIZE + 1));
	buffer = readsave(fd, strstatic);
	if (!buffer)
		return (free(buffer), NULL);
	len = ft_strlen(buffer);
	buffer[len + 1] = '\0';
	strstatic = ft_strrchr(buffer, '\n');
	print = ft_get_line(buffer);
	return (free (buffer), print);
}
