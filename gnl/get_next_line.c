/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:20:08 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/15 10:44:41 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "get_next_line.h"

void	display_file(const int fd)
{
	char buf;

	while (read(fd, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		get_next_line(const int fd, char **line)
{
	int		i;

	i = 1;
	while (line[i])
	{
		fd = open(line[i], O_RDONLY);
		display_file(fd);
		i++;
	}
}
