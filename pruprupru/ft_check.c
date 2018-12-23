/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 04:17:26 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/23 06:11:01 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char*ft_strchr_bis(const char *s, int c)
{
	inti;
	char*sptr;

	i = 0;
	sptr = (char *)s;
	while (sptr[++i] != '\0')
	{
		if (sptr[i] == (char)c)
			return (sptr + i);
	}
	if ('\0' == (char)c)
		return (sptr + i);
	return ((char *)0);
}

void find_directions(t_tetris *elem)
{
	/* code */
	int a;
	int b;
	int c;
	int d;
	char *ptr;

	ptr = (char *)elem->content;
	if (ft_strchr_bis(ptr, 35))
	{
		printf("\n************\nptr = \n%s\n", ptr);
		printf("ptr pour a = \n%s\n", ptr);
		a				 = (ft_strchr_bis(ptr, 35) - ptr) + 1;
		ptr += (a - 1);
		printf("pt				r pour b = \n%s\n", ptr);
		b = (ft_strchr_bis(ptr, 35) - ptr) + a;
		printf("ptr pour c = \n%s\n", ptr);
		ptr += (b - a);
		c = (ft_strchr_bis(ptr, 35) - ptr) + b;
		printf("ptr pour d = \n%s\n", ptr);
		ptr += (c - b);
		d = (ft_strchr_bis(ptr, 35) - ptr) + c;
		printf("ptr= \n%s\n************\n", ptr);
		printf("a = %i | b = %i | c = %i | d = %i\n", a, b, c, d);
		elem->r1 = ((((b - (b / 5)) - 1) / 4) + 1) - ((((a - (a / 5)) - 1) / 4) + 1);
		elem->c1 = ((((b - (b / 5)) - 1) % 4) + 1) - ((((a - (a / 5)) - 1) % 4) + 1);
		elem->r2 = ((((c - (c / 5)) - 1) / 4) + 1) - ((((b - (b / 5)) - 1) / 4) + 1);
		elem->c2 = ((((c - (c / 5)) - 1) % 4) + 1) - ((((b - (b / 5)) - 1) % 4) + 1);
		elem->r3 = ((((d - (d / 5)) - 1) / 4) + 1) - ((((c - (c / 5)) - 1) / 4) + 1);
		elem->c3 = ((((d - (d / 5)) - 1) % 4) + 1) - ((((c - (c / 5)) - 1) % 4) + 1);
		printf("#1->2 = (%i;%i) | #2->3 = (%i;%i) | #3->4 = (%i;%i)\n", elem->r1, elem->c1, elem->r2, elem->c2, elem->r3, elem->c3);
	}
}	

void	ft_check_width_height(t_list **current)
{
	int		i;

	i = 0;
	(*current)->width = 0;
	(*current)->height = 0;
	while ((*current)->content[i])
	{
		while ((*current)->content[i] && (*current)->content[i] != '#')
			i++;
		printf("current->content[i] is = %c\n", (*current)->content[i]);
		if (i / 4 > (*current)->height)
		{
			(*current)->width = i / 4;
		}
		if (i % 4 > (*current)->width)
		{
			(*current)->height = i % 4;;
		}
		i++;
		//	printf("i is = %d\n", i);
	}
	printf("height is = %d \n width is = %d\n", (*current)->height, (*current)->width);
}

