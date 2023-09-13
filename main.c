/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:08:08 by daroldan          #+#    #+#             */
/*   Updated: 2023/09/13 23:20:20 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
char *s;
unsigned int n;
void *buffer;
int fd;
size_t size;
int i;

i = 0;
//s = malloc (11);
fd = open ("file.txt", O_RDONLY);
while (s)
{
	s = get_next_line (fd);
	printf("\n el string es %s", s);
}
free (buffer);
return (0);
}