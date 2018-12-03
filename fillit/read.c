/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 04:38:35 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/03 09:53:57 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stock		*ft_create_elem(t_stock **stock, char *data, int i)
{
	t_stock	*elem;

	elem = *stock;
	if (!(elem = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	elem->stockage = ft_strdup(data);
	elem->index = i;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

int		ft_check(t_stock *stock)
{
	int		i;
	int		k;

	i = 0;
	k = 4;
	while (stock->stockage[i] && i < 21)
	{
		if (i != 0 && i % k == 0)
		{
			if (stock->stockage[i] != '\n')
				return (0);
			i++;
			k += 5;
		}
		if (i == 20 && stock->stockage[i] == '\n')
		{
			return (1);
		}
		if (stock->stockage[i] != '.' && stock->stockage[i] != '#' && i != 20)
			return (0);
		i++;
	}
	if (stock->stockage[i] != '\0')
		return (0);
	return (1);
}

t_stock		*ft_read(char *av, t_stock **head, int *i)
{
	char			buf[21];
	t_stock			*stock;
	int				fd; 
	int				ret;

	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0 && ++(*i) != -1)
	{
		buf[ret] = '\0';
		if (!*head)
		{
			*head = ft_create_elem(&stock, buf, *i);
			stock = *head;
		}
		else
		{
			stock->next = ft_create_elem(&stock->next, buf, *i);
			stock->next->prev = stock;
			stock = stock->next;
		}
		if (!(ft_check(stock)))
			return (NULL);
	}
	return (*head);
}
