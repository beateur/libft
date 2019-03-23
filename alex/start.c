/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:20:16 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:20:19 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <limits.h>

int			pile_count(t_list *pile, long nb, int sup)
{
	int		count;

	count = 0;
	while (pile)
	{
		if (!sup && pile->number < nb)
			count++;
		if (sup && pile->number > nb)
			count++;
		pile = pile->next;
	}
	return (count);
}

t_list		*new_number(t_list *prev, char *number)
{
	t_list	*maillon;

	if (!ft_strisdigit(number))
	{
		ft_color("Error\n", RED);
		return (NULL);
	}
	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if ((maillon->number = ft_atol(number)) > INT_MAX ||
			maillon->number < INT_MIN)
	{
		ft_color("Error\n", RED);
		return (NULL);
	}
	maillon->index = 0;
	maillon->next = NULL;
	maillon->prev = prev;
	return (maillon);
}

void		indexage(t_list *pile)
{
	t_list	*save;

	save = pile;
	while (pile)
	{
		pile->index = pile_count(save, pile->number, 0) + 1;
		pile = pile->next;
	}
}

void		ft_norme_init(t_algo *algo, char **numbers)
{
	t_list	*tmp;
	char	**tab;
	int		i;

	while (*numbers)
	{
		i = 0;
		tab = ft_strsplit(*numbers++, ' ');
		while (tab[i])
		{
			if (!algo->pile_a)
			{
				if (!(algo->pile_a = new_number(NULL, tab[i++])))
					free_algo(algo);
				tmp = algo->pile_a;
			}
			else if (!(tmp->next = new_number(tmp, tab[i++])))
				free_algo(algo);
			else
				tmp = tmp->next;
		}
		ft_free_tab(tab);
	}
}

t_algo		*init_algo(char **numbers)
{
	t_algo	*algo;

	if (!(algo = (t_algo *)malloc(sizeof(t_algo))))
		return (NULL);
	algo->count = 0;
	algo->pile_a = NULL;
	algo->pile_b = NULL;
	ft_norme_init(algo, numbers);
	return (algo);
}
