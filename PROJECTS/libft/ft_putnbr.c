/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:41:05 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 10:41:31 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	ft_putchar(x % 10 + '0');
}
