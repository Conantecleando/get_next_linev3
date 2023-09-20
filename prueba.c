/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:00 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/20 18:39:44 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cont;

	cont = 0;
	while (s[cont])
		cont++;
	return (cont);
}

char	*ft_join(strstatic, buffer)
{
	char		*cube;
	int			len;
	int			cont;
	int			contbis;

	if (!buffer)
		return (strstatic);
	cont = 0;
	contbis = 0;
	while (buffer[cont] != '\0')
		cont++;
	while (strstatic[contbis] != '\0')
		contbis++;
	len = (cont + contbis);
	cube = malloc ((sizeof(char)) * len);
	cube[len + 1] = '\0';
	while (buffer[cont] != '\0')
		*cube[len--] = *buffer[cont--];
	while (strstatic[contbis])
		*cube[len--] = *strstatic[contbis--];
	return (cube);
}		

char	*ft_get_line_sp(len, buffer)
{
	char	*cutline;
	size_t	lenline;

	lenline = 0;
	if (!buffer)
		return (NULL);
	while (*buffer[lenline] != '\n' && *buffer[lenline] != '\0')
		lenline++;
	cutline = malloc ((sizeof(char)) * (lenline + 1));
	cutline[lenline + 1] = '\0';
	while (lenline)
		*cutline[lenline--] = *buffer[lenline--];
	return (cutline);
}

char	*ft_get_new_line(len, buffer)
{
	char	*final;
	size_t	lenfinal;
	size_t	rest;

	if (!buffer)
		return (0);
	lenfinal = 0;
	while (buffer[lenfinal] != '\n' && buffer[lenfinal] != '\0')
		lenfinal++;
	rest = lenfinal - len;
	final = malloc ((sizeof(char)) * (rest + 1));
	final[rest + 1] = '\0';
	while (rest)
		*final[rest--] = *buffer[len--];
	return (final);
}

char	*get_next_line(int fd)
{
	static char		*strstatic = NULL;
	size_t			len;
	char			*buffer;
	char			*line;

	if (fd <= 0 || (BUFFER_SIZE < 1))
		return (NULL);
len = 0;
buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
len = read(fd, buffer, BUFFER_SIZE);
	if (strstatic)
		strstatic = ft_join((char *)strstatic, (char *)buffer);
	if (len < 0)
		return (free (buffer), NULL);
	else if (len == 0)
		return (free (buffer), strstatic);
	else if (len > 0)
	{
		buffer[len + 1] = '\0';
		line = ft_get_line_sp(len, (char *)buffer);
		strstatic = ft_get_new_line(len, buffer);
	}
free (buffer);
line[ft_strlen(line) + 1] = '\0';
	return (line);
}
