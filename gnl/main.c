/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:15:54 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/15 11:05:34 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		const int		fd = open(argv[i], O_RDONLY);
		get_next_line(fd, argv);
		i++;
	}
	return (0);
}
