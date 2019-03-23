/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:48:30 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 05:38:10 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char		*ulitoa(unsigned long number)
{
	int		n;
	char	*array;

	n = 0;
	array = ft_strnew(llong_len(number));
	while (number)
	{
		ft_strncat(array, &ALNUM[(number % 10)], 1);
		number /= 10;
	}
	ft_str_reverse(array);
	return (array);
}
