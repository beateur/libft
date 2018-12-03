/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:40:22 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/11 04:40:37 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ptr;
	char	*psrc;

	ptr = dest;
	psrc = (char *)src;
	while (*ptr)
		ptr++;
	while (*psrc && n-- > 0)
		*ptr++ = *psrc++;
	*ptr = '\0';
	return (dest);
}
