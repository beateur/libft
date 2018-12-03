/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:59:19 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/03 09:33:40 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
//#include "../realgnl/libft/libft.h"

void				ft_put_up_left(t_stock **list)
{
	t_stock			*head;

	head = *list;
	while (!(head->type & 1))
	{
		head->type = head->type >> 1;
	}
	ft_printbits(head->type);
	ft_putchar('\n');
	head = head->next;
}

int					ft_binary(t_stock **head)
{
	int		i;
	t_stock	*current;

	current = *head;
	while (current)
	{
		i = 0;
		while (current->stockage[i])
		{
			if (current->stockage[i] == '#')
				current->type |= 1 << (i - i / 5);
			i++;
		}
		ft_put_up_left(&current);
		current = current->next;
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_stock			*head;
	int				i;

	i = -1;
	head = NULL;
	if (ac != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		return (0);
	}
	if ((head = ft_read(av[1], &head, &i)) == NULL)
	{
		write(2, "error\n", 6);
		return (0);
	}
	ft_binary(&head);
	ft_init(&head);
	return (0);
}
