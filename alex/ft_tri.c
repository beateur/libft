/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:15:26 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:15:31 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long		calculate_pivot(t_list *pile)
{
	int		index_max;

	indexage(pile);
	index_max = 0;
	while (pile->next)
	{
		if (index_max < pile->index)
			index_max = pile->index;
		pile = pile->next;
	}
	index_max = index_max % 2 ? index_max / 2 + 1 : index_max / 2;
	while (pile->prev && pile->index != index_max)
		pile = pile->prev;
	return (pile->number);
}

void		split_by_pivot(t_algo *algo)
{
	int		tmp;
	int		count;
	long	pivot;

	while (algo->pile_a)
	{
		pivot = calculate_pivot(algo->pile_a);
		count = pile_count(algo->pile_a, pivot, 0) + 1;
		while (count)
		{
			if (algo->pile_a->number <= pivot)
			{
				if (algo->pile_b)
					tmp = calculate_pivot(algo->pile_b);
				action_pb(algo, 1);
				if (algo->pile_b && algo->pile_b->number < tmp)
					action_rb(algo, 1);
				if (!(algo->pile_a))
					break ;
				count--;
			}
			else
				action_ra(algo, 1);
		}
	}
}

void		check_next_index(t_algo *algo, int index)
{
	t_list	*tmp;
	int		path;
	int		next;

	path = 0;
	next = 0;
	if (!algo->pile_a || !(tmp = algo->pile_b))
		return ;
	while (tmp && tmp->index != index - 1)
	{
		tmp = tmp->next;
		path++;
	}
	path = path > ft_len_list(algo->pile_b) / 2 ? 1 : 0;
	while (algo->pile_b->index != index - 1)
	{
		if (algo->pile_b->index == index - 2 && (next = 1))
			action_pa(algo, 1);
		else
			path == 1 ? action_rrb(algo, 1) : action_rb(algo, 1);
	}
	action_pa(algo, 1);
	next ? action_sa(algo, 1) : 0;
}

void		quick_sort(t_algo *algo)
{
	if (check_pile(algo))
		return ;
	split_by_pivot(algo);
	action_pb(algo, 1);
	indexage(algo->pile_b);
	action_pa(algo, 1);
	while (!check_pile(algo))
		check_next_index(algo, algo->pile_a->index);
}
