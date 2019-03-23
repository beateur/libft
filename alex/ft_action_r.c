/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:14:25 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:14:26 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			action_ra(t_algo *algo, int checker)
{
	t_list		*tmp;

	if (!(tmp = algo->pile_a) || !(tmp->next))
		return (0);
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp->next)
	{
		ft_long_swap(&(tmp->number), &(tmp->next->number));
		ft_int_swap(&(tmp->index), &(tmp->next->index));
		tmp = tmp->next;
	}
	algo->count++;
	if (checker)
		ft_putstr("ra\n");
	return (1);
}

int			action_rb(t_algo *algo, int checker)
{
	t_list		*tmp;

	if (!(tmp = algo->pile_b) || !(tmp->next))
		return (0);
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp->next)
	{
		ft_long_swap(&(tmp->number), &(tmp->next->number));
		ft_int_swap(&(tmp->index), &(tmp->next->index));
		tmp = tmp->next;
	}
	algo->count++;
	if (checker)
		ft_putstr("rb\n");
	return (1);
}

int			action_rr(t_algo *algo, int checker)
{
	if (!action_ra(algo, 0) + action_rb(algo, 0) == 2)
		algo->count--;
	if (checker)
		ft_putstr("rr\n");
	return (1);
}
