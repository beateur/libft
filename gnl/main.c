/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:15:54 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/15 10:44:39 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(*argv, O_RDONLY);
	get_next_line((const int)fd, argv);
}
