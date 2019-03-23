/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:14:16 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:34:03 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			action_pb(t_algo *algo, int checker)
{
	t_list		*save;

	if (!(save = algo->pile_a))
		return (0);
	if ((algo->pile_a = algo->pile_a->next))
		algo->pile_a->prev = NULL;
	if (algo->pile_b)
	{
		algo->pile_b->prev = save;
		if (save->next)
			save->next->prev = NULL;
		algo->pile_b->prev->next = algo->pile_b;
		algo->pile_b = algo->pile_b->prev;
	}
	else
	{
		algo->pile_b = save;
		save->next->prev = NULL;
		algo->pile_b->next = NULL;
		algo->pile_b->prev = NULL;
	}
	algo->count++;
	if (checker)
		ft_putstr("pb\n");
	return (1);
}

int			action_pa(t_algo *algo, int checker)
{
	t_list		*save;

	if (!(save = algo->pile_b))
		return (0);
	if ((algo->pile_b = algo->pile_b->next))
		algo->pile_b->prev = NULL;
	if (algo->pile_a)
	{
		algo->pile_a->prev = save;
		save->next = algo->pile_a;
		algo->pile_a = save;
	}
	else
	{
		algo->pile_a = save;
		algo->pile_a->next = NULL;
	}
	algo->count++;
	if (checker)
		ft_putstr("pa\n");
	return (1);
}
