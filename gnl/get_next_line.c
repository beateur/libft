/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:20:08 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/17 07:00:08 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
//#include "get_next_line.h"

void	display_file(const int fd)
{
	char buf;

	while (read(fd, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[1];
	char	*tab;
	char	*tmp;

	if (!(tab = malloc(sizeof(char) * (1))) || (fd == -1))
		return (0);
	while ((read(0, buff, 1) > 0))
	{
		tmp = tab;
		if (!(tab = malloc(sizeof(*tab) * (++i + 1))))
			return (0);
		tab[0] = '\0';
		strncat(tab, tmp, i + 1);
		strncat(tab, buff, 1);
	}
	free(tmp);
	return (0);
}
