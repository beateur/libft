/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:10:41 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:10:44 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char*)dest;
	csrc = (char*)src;
	if (csrc < cdest)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
		ft_memcpy(cdest, csrc, n);
	return (cdest);
}
