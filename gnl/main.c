/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:15:54 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/22 00:35:43 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
//#define BUF_SIZE 1
int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	const int	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, argv);
	printf("%s", *line);
	return (0);
}
