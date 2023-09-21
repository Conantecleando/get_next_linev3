/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:00 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/21 23:27:55 by daroldan         ###   ########.fr       */
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

char	*ft_join(char	*strstatic, char	*buffer)
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
	cont = -1;
	contbis = -1;
	while (buffer[++cont] != '\0')
		cube[cont] = buffer[cont];
	while (strstatic[++contbis])
		cube[(cont + contbis)] = strstatic[contbis];
	return (cube);
}		

char	*ft_get_line_sp(size_t len, char	*buffer)
{
	char	*cutline;
	size_t	lenline;

	lenline = -1;
	len = -1;
	if (!buffer)
		return (NULL);
	while (buffer[++lenline] != '\0')
	{	
		if (buffer[lenline] == '\n')
		{
			cutline = malloc ((sizeof(char)) * (lenline + 1));
			while (++len != lenline)
			{
				cutline[len] = buffer [len];
				if (len == lenline)
				{
					cutline[lenline + 1] = '\0';
					return (cutline);
				}
			}
		}
	}
	return (NULL);
}

char	*ft_get_new_line(size_t len, char	*buffer)
{
	char	*final;
	size_t	lenfinal;

	if (!buffer)
		return (NULL);
	lenfinal = -1;
	while (buffer[++lenfinal] != '\0')
	{	
		if (buffer[lenfinal] == '\n')
		{
			final = malloc ((sizeof(char)) * (len - lenfinal));
			while ((len - lenfinal) != 0)
			{
				final[lenfinal] = buffer [lenfinal];
				if (len == lenfinal)
				{
					final[lenfinal + 1] = '\0';
					return (final);
				}
				lenfinal++;
			}
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*strstatic = NULL;
	size_t			len;
	char			*buffer;
	char			*line;

	if (fd <= 0 || (BUFFER_SIZE < 1))
		return (NULL);
	len = 1;
	buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	while (len > 0 && )
	{
		len = read(fd, buffer, BUFFER_SIZE);
		buffer[len] = '\0';
		if (strstatic)
			strstatic = ft_join(strstatic, buffer);
		if (len < 0)
			return (free (buffer), NULL);
		else if (len == 0)
			return (free (buffer), strstatic);
		strstatic = ft_get_line_sp(len, buffer);
		line = ft_get_new_line(len, buffer);
	}
	free (buffer);
	line[ft_strlen(line) + 1] = '\0';
	return (line);
}
