/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:15:54 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/17 06:40:43 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	int 	j;
	const int fd = open(*argv, O_RDONLY);

	j = 1;
	while (j++ < argc)
		get_next_line(fd, argv);
	return (0);
}
