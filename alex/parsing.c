/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:16:01 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:19:29 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			check_pile(t_algo *algo)
{
	t_list	*pile;

	if (!(pile = algo->pile_a) || algo->pile_b)
		return (0);
	while (pile->next)
	{
		if (pile->number > pile->next->number)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int			list_is_valid(t_algo *algo)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(tmp = algo->pile_a))
		return (0);
	while (tmp->next)
	{
		tmp2 = tmp;
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
			if (tmp->number == tmp2->number)
			{
				ft_color("Error\n", RED);
				exit(0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
