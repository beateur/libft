/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:48:31 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/11 04:49:18 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	cur;

	i = 0;
	cur = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && n > i)
	{
		if (s1[i + cur] == s2[cur] && i + cur < n)
			cur++;
		else
		{
			cur = 0;
			i++;
		}
		if (!s2[cur])
			return ((char *)s1 + i);
	}
	return (0);
}
