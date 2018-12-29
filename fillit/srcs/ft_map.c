/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 05:06:51 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/29 07:27:12 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_map_elem(int size)
{
	int			row;
	t_map		*map;

	row = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->set = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (row < size)
	{
		if (!(map->set[row] = ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		map->set[row] = (char *)ft_memset((void *)map->set[row], '.', size);
		row++;
	}
	map->set[size] = NULL;
	map->size = size;
	return (map);
}

void		print_map(t_map *map, t_tetris *pieces)
{
	int		i;
	t_map	*save;

	i = 0;
	save = map;
	while (i < map->size)
		ft_putendl(map->set[i++]);
	ft_free(&pieces, &save, 0);
}
