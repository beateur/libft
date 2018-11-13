/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:50:10 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 09:50:38 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	i = 0;
	if (tab == 0)
		return ;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
