/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:19:10 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:19:12 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *little)
{
	int i;
	int x;

	if (little[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		x = 0;
		while (little[x] == str[i + x])
		{
			if (!little[x + 1])
				return ((char *)(str + i));
			x++;
		}
		i++;
	}
	return (NULL);
}
