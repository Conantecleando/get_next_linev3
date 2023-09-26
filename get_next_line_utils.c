/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:04:41 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/26 03:11:58 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		p[n] = 0;
}

void	*ft_calloc(size_t h, size_t len)
{
	void	*ptr;

	ptr = malloc (h * len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (h * len));
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	cont;

	cont = 0;
	if (!s || s[cont] == '\0')
	{
		return (0);
	}
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
	j[len + 1] = '\0';
	return (j);
}

char	*ft_strrchr(char *chain, int c)
{
	int		j;
	int		s;
	char	*subchain;

	j = ft_strlen(chain);
	s = 0;
	while (chain && j != s)
	{
		while (chain[s] != (char)c)
		{
			s++;
			if (s > j)
				return (NULL);
		}
		if (chain[s])
		{
			subchain = malloc ((sizeof(char)) * (s + 1));
			if (!subchain)
				return (free(subchain), NULL);
			subchain = &chain[s + 1];
			subchain[s + 1] = '\0';
			return (free(chain), subchain);
		}
	}
	return (NULL);
}

char	*ft_strchr(char *chain, int c)
{
	unsigned int	j;
	unsigned int	len;
	char			*subchain;

	len = 0;
	while (chain[len] != '\0')
		len++;
	if (!chain)
		return (NULL);
	j = 0;
	while (len != j)
	{
		if (chain[j] == (char)c)
		{
			subchain = malloc ((sizeof(char)) * (j + 1));
			if (!subchain)
				return (free(subchain), NULL);
			subchain = &chain[j + 1];
			subchain[j + 1] = '\0';
			return (free(chain), subchain);
		}
		j++;
	}
	return (NULL);
}
