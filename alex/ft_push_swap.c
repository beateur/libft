/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:15:10 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:34:32 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_norme(t_algo *algo)
{
	int		len;

	len = ft_len_list(algo->pile_a);
	if (len == 2)
		ft_tri_2(algo);
	else if (len == 3)
		ft_tri_3(algo);
	else if (len == 5)
		ft_tri_5(algo);
	else
		quick_sort(algo);
	if (algo->visu)
		print_piles(algo);
}

int			main(int ac, char **av)
{
	int		visu;
	t_algo	*algo;

	if (ac == 1)
		return (1);
	visu = 0;
	if (ft_strequ(av[1], "-v"))
		visu = 1;
	if (!(algo = init_algo(av + 1 + visu)))
		return (0);
	algo->visu = visu;
	if (!list_is_valid(algo))
		ft_color("Error\n", RED);
	else if (check_pile(algo))
		;
	else
		ft_norme(algo);
	free_algo(algo);
	return (0);
}
