/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:52:47 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/22 03:53:20 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_init(int size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		map[i] = (char *)ft_memset((void *)map[i], '.', size);
		i++;
	}
	map[size] = NULL;
	return (map);
}
