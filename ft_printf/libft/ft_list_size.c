/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:58:43 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 10:00:32 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	if (begin_list == (void*)0)
		return (0);
	i = 1;
	list = begin_list->next;
	while (list != (void*)0 && i++)
		list = list->next;
	return (i);
}
