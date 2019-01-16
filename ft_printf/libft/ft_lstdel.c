/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:16:18 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 15:52:47 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*maillon;
	t_list	*tmp;

	maillon = *alst;
	while (maillon)
	{
		del(maillon->content, maillon->content_size);
		tmp = maillon;
		maillon = maillon->next;
		free(tmp);
	}
	*alst = NULL;
}
