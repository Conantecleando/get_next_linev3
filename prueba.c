/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidrol <davidrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:00 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/24 15:24:05 by davidrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	cont;

	cont = 0;
	while (s[cont])
		cont++;
	return (cont);
}

char	*ft_join(char *strstatic, char *buffer)
{
	char		*cube;
	int			len;
	int			cont;
	int			contbis;

	if (!strstatic)
		strstatic = malloc((sizeof (char)) * 1);
	if (!buffer)
		return (strstatic);
	cont = 0;
	contbis = 0;
	len = (ft_strlen(buffer) + ft_strlen(strstatic));
	cube = malloc ((sizeof(char)) * len);
	while (buffer[cont] != '\0'&& buffer)
		cube[cont] = buffer[cont++];
	while (strstatic[contbis] != '\0' && strstatic)
		cube[cont + contbis] = strstatic[contbis++];
	cube[len + 1] = '\0';
	return (cube);
}		

char	*ft_get_line_sp(size_t len, char *buffer)
{
	char	*cutline;
	size_t	lenline;
	size_t	cont;
	size_t	contbuf;

	lenline = 0;
	cont = 0;
	contbuf = 0;
	if (!buffer)
		return (NULL);
	while (buffer[lenline] != '\n' && buffer[lenline] != '\0')
		lenline++;
	cutline = malloc ((sizeof(char)) * (lenline + 1));
	while (lenline >= cont)
		cutline[cont++] = buffer[contbuf++];
	cutline[lenline + 1] = '\0';
	return (cutline);
}

char	*ft_get_new_line(size_t len, char *buffer)
{
	char	*final;
	size_t	lenfinal;
	size_t	rest;
	size_t	cont;

	if (!buffer)
		return (0);
	lenfinal = 0;
	while (buffer[lenfinal] != '\n' && buffer[lenfinal] != '\0')
		lenfinal++;
	rest = lenfinal - len;
	final = malloc ((sizeof(char)) * (rest + 1));
	if (rest <= 0)
		return (free(final), NULL);
	while (rest != cont)
		final[cont] = buffer[cont++];
	final[rest + 1] = '\0';
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
	while (!buffer[len])
	{
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
			line = ft_join (strstatic, buffer);
			strstatic = ft_get_new_line(len, buffer);
		}
	}
	free (buffer);
line[ft_strlen(line) + 1] = '\0';
	return (line);
}
