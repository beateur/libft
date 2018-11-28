/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:17:09 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 03:48:40 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	if (!(ft_strchr(s, c)))
		return (NULL);
	while (i-- > 0 && s[i] != c)
		;
	return ((char *)s + i);
}
