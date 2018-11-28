/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:41:07 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 00:14:45 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*psrc;
	int		i;

	psrc = (char *)src;
	i = 0;
	while (*psrc)
		dest[i++] = *psrc++;
	dest[i] = '\0';
	return (dest);
}
