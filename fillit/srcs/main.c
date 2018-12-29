/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:30:07 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/29 07:59:17 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				fd;
	t_tetris		*pieces;
	t_map			*map;
	int				size;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit input_file\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	pieces = create_tetris_elem(0, "start", 5);
	if (!parse_input(fd, pieces))
	{
		ft_free(&pieces, &map, 1);
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	pieces = pieces->next;
	size = ft_sqrt((count_tetris(pieces)) * 4);
	map = create_map_elem(size++);
	while (!solve(pieces, map))
		map = create_map_elem(size++);
	print_map(map, pieces);
	return (1);
}
