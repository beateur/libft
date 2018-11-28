/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:21:48 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/11 04:39:06 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	current;

	i = 0;
	current = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i + current] == s2[current])
			current++;
		else
		{
			current = 0;
			i++;
		}
		if (!s2[current])
			return ((char *)s1 + i);
	}
	return (0);
}
