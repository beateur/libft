/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:22:31 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 00:19:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*psrc;
	size_t	i;

	psrc = (char *)src;
	i = 0;
	while (*psrc && i < n)
		dest[i++] = *psrc++;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
