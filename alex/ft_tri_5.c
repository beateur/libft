/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:15:44 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:15:45 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_norme_min(t_algo *algo, int min, int path)
{
	while (algo->pile_a->next && algo->pile_a->number != min)
	{
		min = get_min(algo->pile_a);
		if (algo->pile_a->number == min)
		{
			action_pb(algo, 1);
			return ;
		}
		path == 1 ? action_rra(algo, 1) : action_ra(algo, 1);
		if (algo->pile_a->number == min)
		{
			action_pb(algo, 1);
			return ;
		}
	}
}

void		check_next_min(t_algo *algo)
{
	t_list	*tmp;
	int		path;
	int		min;

	path = 0;
	if (!(tmp = algo->pile_a) || !algo->pile_b)
		return ;
	min = get_min(algo->pile_a);
	while (tmp && tmp->number != min)
	{
		tmp = tmp->next;
		path++;
	}
	path = path > ft_len_list(algo->pile_b) / 2 ? 1 : 0;
	if (algo->pile_a->number == min)
	{
		action_pb(algo, 1);
		return ;
	}
	ft_norme_min(algo, min, path);
}

void		ft_norme_max(t_algo *algo, int max, int path)
{
	while (algo->pile_a->next && algo->pile_a->number != max)
	{
		max = get_max(algo->pile_a);
		if (algo->pile_a->number == max)
		{
			action_pb(algo, 1);
			return ;
		}
		path == 1 ? action_rra(algo, 1) : action_ra(algo, 1);
		if (algo->pile_a->number == max)
		{
			action_pb(algo, 1);
			return ;
		}
	}
}

void		check_next_max(t_algo *algo)
{
	t_list	*tmp;
	int		path;
	int		max;

	path = 0;
	if (!(tmp = algo->pile_a) || algo->pile_b)
		return ;
	max = get_max(algo->pile_a);
	if (algo->pile_a->number == max)
	{
		action_pb(algo, 1);
		return ;
	}
	while (tmp && tmp->number != max)
	{
		tmp = tmp->next;
		path++;
	}
	if (path == 2)
		path = path - 2;
	path = path > ft_len_list(algo->pile_b) / 2 ? 1 : 0;
	ft_norme_max(algo, max, path);
}

void		ft_tri_5(t_algo *algo)
{
	int min;
	int max;

	max = get_max(algo->pile_a);
	if (algo->pile_a->next->number == max)
		action_sa(algo, 1);
	check_next_max(algo);
	min = get_min(algo->pile_a);
	check_next_min(algo);
	ft_tri_3(algo);
	action_pa(algo, 1);
	action_pa(algo, 1);
	action_ra(algo, 1);
}
