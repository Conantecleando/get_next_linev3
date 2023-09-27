/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:24:58 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/27 22:04:06 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char **str, char *str2)
{
	char	*s3;

	if (!(*str))
	{
		*str = malloc ((sizeof(char)));
		if (!*str)
			return (0);
		(*str)[0] = '\0';
	}
	s3 = ft_strjoin(*str, str2);
	free (*str);
	return (s3);
}

char	*readsave(int fd, char	**strold)
{
	char		buffer[BUFFER_SIZE + 1];
	int			posstr;

	posstr = 1;
	while (posstr > 0 && !ft_strchr(*strold, '\n'))
	{	
		posstr = read(fd, buffer, BUFFER_SIZE);
		if (posstr < 0)
		{
			free (*strold);
			*strold = NULL;
			return (NULL);
		}
		buffer[posstr] = '\0';
		if (posstr < BUFFER_SIZE)
			return (ft_joinfree(strold, buffer));
		*strold = ft_joinfree(strold, buffer);
		(*strold)[ft_strlen(*strold)] = '\0';
	}
	return (*strold);
}

char	*ft_get_line(char	*buffer)
{
	int			pos;
	char		*line;

	pos = 0;
	if (!buffer[pos])
		return (NULL);
	while (buffer[pos] != '\n' && buffer[pos])
		pos++;
	line = malloc((sizeof(char)) * (pos + 1 + (buffer[pos] == '\n')));
	if (!line)
		return (NULL);
	pos = 0;
	while (buffer[pos] != '\n' && buffer[pos])
	{
		line[pos] = buffer[pos];
		pos++;
	}
	if (buffer[pos] == '\n')
	{
		line[pos] = buffer[pos];
		pos++;
	}
	line[pos] = '\0';
	return (line);
}

char	*ft_get_static(char *buffer)
{
	char	*stack;

	stack = ft_strchr(buffer, '\n');
	if (stack)
		return (ft_strdup(stack + 1));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*strstatic = NULL;
	size_t			len;
	char			*buffer;	
	char			*print;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	if (strstatic)
	{	
		if (ft_strchr(strstatic, '\n'))
			buffer = strstatic;
		else
			buffer = readsave(fd, &strstatic);
	}
	else
		buffer = readsave(fd, &strstatic);
	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer);
	strstatic = ft_get_static(buffer);
	print = ft_get_line(buffer);
	free (buffer);
	return (print);
}
