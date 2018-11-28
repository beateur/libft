/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:41:01 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 06:32:59 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (*s)
		{
			new[i] = (*f)(i, *s);
			s++;
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
