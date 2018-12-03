/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:39:52 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/03 10:01:09 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_solve(t_stock **curr, char **map)
{
	int		i;
	char	*ptr;

	ptr = *map;
	i = 0;
	while  (ptr[i])
	{
		if (ptr[i] != '.')
			i++;

	}
	return (1);
}

int				ft_init(t_stock **head)
{
	t_stock		*curr;
	char		*map;
	int			size;
	int			i;
	int			k;

	i = -1;
	curr = *head;
	while (curr && curr->next)
		curr = curr->next;
	size = ft_sqrt((curr->index + 1) * 4);
	k = size;
	map = ft_strnew((size * size));
	while (++i < (size * (size + 1)))
	{
		map[i] = '.';
		if (i != 0 && i % k  == 0)
		{
			map[i] = '\n';
			k += size + 1;
		}
	}
//	ft_solve(head, &map);
	return(1);
}

