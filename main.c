/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:08:08 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/26 01:36:48 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_leaks(void)
{
	printf("\nLEAKs OK¡");
	system("leaks -q a.out");
}

int main(void)
{
char *s;
int fd;

fd = open ("file.txt", O_RDONLY);
while (s)
{
	s = get_next_line (fd);
	printf("\n el string es %s", s);
}
atexit(ft_leaks);
return (0);
}