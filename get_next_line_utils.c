/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:04:41 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/18 02:29:14 by daroldan         ###   ########.fr       */
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
	int	cont;

	cont = 0;
	if (!s)
		return (1);
	while (s[cont])
		cont++;
	return (cont);
}

char	*ft_strrchr(char *chain, int c)
{
	int		j;
	int		s;

	j = ft_strlen(chain);
	s = 0;
	while (chain && j >= s)
	{
		while (chain[s] != (char)c)
		{
			s++;
			if (s > j)
				return (NULL);
		}
		if (chain[s])
			return ((char *)chain + (s + 1));
	}
	return (NULL);
}

char	*ft_strchr(char *chain, int c)
{
	unsigned int	j;
	unsigned int	len;

	len = ft_strlen(chain);
	j = 0;
	while (len >= j)
	{
		if (chain[j] == (char)c)
			return ((char *) &chain[j]);
		j++;
	}
	return (NULL);
}
