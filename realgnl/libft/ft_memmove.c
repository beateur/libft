/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:30:20 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 08:02:43 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destc;
	char	*srcc;

	destc = (char *)dest;
	srcc = (char *)src;
	if (destc > srcc)
	{
		destc += n - 1;
		srcc += n - 1;
		while (n-- > 0)
			*destc-- = *srcc--;
	}
	else
	{
		while (n-- > 0)
			*destc++ = *srcc++;
	}
	return (dest);
}
