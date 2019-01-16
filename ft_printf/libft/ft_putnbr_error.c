/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:53:56 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/28 04:53:57 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_error(int n)
{
	unsigned int	x;

	x = n;
	if (n < 0)
	{
		ft_putchar_error('-');
		x = -x;
	}
	if (x > 9)
		ft_putnbr_error(x / 10);
	ft_putchar_error(x % 10 + '0');
}
