/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:50:51 by bihattay          #+#    #+#             */
/*   Updated: 2019/03/11 05:30:51 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"
int y;
int		ft_printf_integer(t_options *option, va_list *args)
{
	long long	n;
	int			len;
	int			ret;

	ret = 0;
	n = get_type(option, args);
	len = ft_nbrlen(n, 10) - (n == 0);
//	printf("\n\n\n\n\n\nnb %d ---> %lld len ------>%d\n\n\n\n\n", y++, n, len);
	if (n < 0)
		option->neg = 1;
	if (n == 0 && option->point)
		len = 0;
	ret += helper_nb_pad(option, len, 0, n);
	if (!(n == 0 && option->point))
		ret += ft_putnbr(n);
	ret += helper_nb_pad(option, len, 1, n);
	return (ret);
}
