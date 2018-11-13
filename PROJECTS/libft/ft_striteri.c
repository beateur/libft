/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:27:23 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 10:10:36 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*ptr)
	{
		(*f)(i, ptr);
		i++;
		ptr++;
	}
}
