/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:27:25 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 15:51:40 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*first;

	if (lst)
	{
		tmp = f(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		first = new;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			new->next = ft_lstnew(tmp->content, tmp->content_size);
			new = new->next;
			lst = lst->next;
		}
		return (first);
	}
	else
		return (NULL);
}
