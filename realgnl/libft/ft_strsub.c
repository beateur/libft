/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 04:11:42 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 06:44:50 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if ((char)s[start + i] == '\0')
			return (NULL);
		copy[i] = (char)s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
