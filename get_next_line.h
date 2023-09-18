/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:28:14 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/18 01:45:12 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_joinfree(char *str, char *str2);
char	*readsave(int fd, char	*strold);
char	*ft_get_line(char	*buffer);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t h, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strrchr(char *chain, int c);
char	*ft_strchr(char *chain, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif
#endif