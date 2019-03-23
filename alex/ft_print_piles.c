/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:14:56 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:15:01 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		print_lists(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("| %5ld | %-5ld |\n", a->number, b->number);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			ft_printf("| %5ld |       |\n", a->number);
			a = a->next;
		}
		else if (b)
		{
			ft_printf("|       | %-5ld |\n", b->number);
			b = b->next;
		}
		ft_putstr("*---------------*\n");
	}
}

void			print_piles(t_algo *algo)
{
	t_list		*a;
	t_list		*b;

	a = algo->pile_a;
	b = algo->pile_b;
	ft_putstr("*---------------*\n");
	ft_printf("|   A:  |   B:  |\n");
	ft_putstr("*---------------*\n");
	print_lists(a, b);
	ft_printf("| hits: %-7d |\n", algo->count);
	ft_putstr("*---------------*\n");
}

void			print_result(t_algo *algo)
{
	if (check_pile(algo) && !(algo->pile_b))
		ft_color("OK\n", GREEN);
	else
		ft_color("KO\n", RED);
}
