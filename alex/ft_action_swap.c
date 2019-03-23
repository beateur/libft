/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:20:00 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:20:03 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			action_sa(t_algo *algo, int checker)
{
	if (algo->pile_a && algo->pile_a->next)
	{
		ft_long_swap(&(algo->pile_a->number), &(algo->pile_a->next->number));
		ft_int_swap(&(algo->pile_a->index), &(algo->pile_a->next->index));
		algo->count++;
	}
	else
		return (0);
	if (checker)
		ft_putstr("sa\n");
	return (1);
}

int			action_sb(t_algo *algo, int checker)
{
	if (algo->pile_b && algo->pile_b->next)
	{
		ft_long_swap(&(algo->pile_b->number), &(algo->pile_b->next->number));
		ft_int_swap(&(algo->pile_b->index), &(algo->pile_b->next->index));
		algo->count++;
	}
	else
		return (0);
	if (checker)
		ft_putstr("sb\n");
	return (1);
}

int			action_ss(t_algo *algo, int checker)
{
	if (action_sa(algo, 0) + action_sb(algo, 0) == 2)
		algo->count--;
	if (checker)
		ft_putstr("ss\n");
	return (1);
}
