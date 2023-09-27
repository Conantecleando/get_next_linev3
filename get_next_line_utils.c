/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:04:41 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/27 22:06:32 by daroldan         ###   ########.fr       */
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
		return (NULL);
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

size_t	ft_strlen(char *s)
{
	size_t	cont;

	cont = 0;
	if (!s)
		return (0);
	while (s[cont])
		cont++;
	return (cont);
}

char	*ft_strdup(char *source)
{
	size_t	h;
	char	*j;
	size_t	len;

	h = ft_strlen(source);
	if (source == NULL)
		return (NULL);
	j = malloc((sizeof(char)) * (h + 1));
	if (!j)
		return (NULL);
	len = 0;
	while (len < h)
	{
		j[len] = source[len];
		len++;
	}
	j[len] = '\0';
	return (j);
}

char	*ft_strchr(char *chain, int chr)
{
	int	j;

	j = 0;
	if (!chain)
		return (NULL);
	if (chain[j] == 0 && chr == 0)
		return ((char *)chain);
	while (chain[j] != '\0')
	{
		if (chain[j] == (char)chr)
			return ((char *) &chain[j]);
		j++;
		if (chain[j] == '\0')
		{
			if ((char)chr == '\0')
				return ((char *) &chain[j]);
			else
				return (0);
		}
	}
	return (0);
}
