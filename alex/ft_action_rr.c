/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 02:07:14 by kaboujna          #+#    #+#             */
/*   Updated: 2019/03/04 02:07:40 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			action_rra(t_algo *algo, int checker)
{
	t_list		*last;

	if (!(last = algo->pile_a))
		return (0);
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		ft_long_swap(&(last->number), &(last->prev->number));
		ft_int_swap(&(last->index), &(last->prev->index));
		last = last->prev;
	}
	algo->count++;
	if (checker)
		ft_putstr("rra\n");
	return (1);
}

int			action_rrb(t_algo *algo, int checker)
{
	t_list		*last;

	if (!(last = algo->pile_b))
		return (0);
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		ft_long_swap(&(last->number), &(last->prev->number));
		ft_int_swap(&(last->index), &(last->prev->index));
		last = last->prev;
	}
	algo->count++;
	if (checker)
		ft_putstr("rrb\n");
	return (1);
}

int			action_rrr(t_algo *algo, int checker)
{
	if (!action_rra(algo, 0) + action_rrb(algo, 0) == 2)
		algo->count--;
	if (checker)
		ft_putstr("rrr\n");
	return (1);
}
