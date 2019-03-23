/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:15:51 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:31:48 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	count_err(t_list *list)
{
	int		error;

	error = 0;
	while (list->next)
	{
		if (list->number > list->next->number)
			error++;
		list = list->next;
	}
	printf("\nerror = %d\n", error);
}

int		get_max(t_list *tmp)
{
	int		max;

	max = tmp->number;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

int		get_min(t_list *tmp)
{
	int		min;

	min = tmp->number;
	while (tmp)
	{
		if (tmp->number < min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

void	free_algo(t_algo *algo)
{
	t_list		*tmp;
	t_list		*save;

	tmp = algo->pile_a;
	while (tmp)
	{
		save = tmp->next;
		free(tmp);
		tmp = save;
	}
	tmp = algo->pile_b;
	while (tmp)
	{
		save = tmp->next;
		free(tmp);
		tmp = save;
	}
	free(algo);
	exit(0);
}

void	wait_user(t_algo *algo)
{
	char	ret;

	print_piles(algo);
	while (read(1, &ret, 1) > 0)
	{
		if (ret == '\n')
			break ;
	}
}
