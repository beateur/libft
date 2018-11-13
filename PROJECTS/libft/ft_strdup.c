/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:28:03 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 08:16:48 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		return (NULL);
	if (src)
	{
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
