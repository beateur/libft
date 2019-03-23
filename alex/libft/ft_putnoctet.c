/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnoctet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:13:23 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:13:24 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnoctet(void *str, size_t n)
{
	unsigned char *cstr;

	cstr = (unsigned char *)str;
	while (n > 0)
	{
		ft_putchar(*cstr);
		cstr++;
		n--;
	}
}
