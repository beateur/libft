/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:08:35 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:08:36 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int number, int base)
{
	char	i;
	char	set[35];
	char	*convert;

	if (number > INT32_MAX)
		return (ft_itoa(INT32_MAX));
	if (number < INT32_MIN)
		return (ft_itoa(INT32_MIN));
	if (base < 2 || base == 10 || base > 35)
		return (ft_itoa(number));
	i = 0;
	convert = ft_strnew(33);
	ft_strcpy(set, "0123456789abcdefghijklmnopqrstuvwxyz");
	while (number)
	{
		ft_strncat(convert, set + (number / ft_power(base, i)), 1);
		number -= base * (number / ft_power(base, i++));
	}
	return (convert);
}
