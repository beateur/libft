/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:13:08 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 00:48:48 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;

	ps = (char *)s;
	while (*ps)
	{
		if (*ps == c)
			return (ps);
		ps++;
	}
	if (*ps == c)
		return (ps);
	return (NULL);
}
