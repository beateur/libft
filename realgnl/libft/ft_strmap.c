/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:31:14 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 10:12:22 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ptr = new;
	while (*s)
		*ptr++ = (*f)(*s++);
	*ptr = '\0';
	return (new);
}
