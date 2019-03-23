/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:04:24 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 02:47:50 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

long long int	flag_h(va_list arg)
{
	unsigned short int	ret;

	ret = va_arg(arg, unsigned int);
	return ((long long int)ret);
}

long long int	flag_hh(va_list arg)
{
	unsigned char	ret;

	ret = va_arg(arg, signed int);
	return ((long long int)ret);
}

long long int	flag_l(va_list arg)
{
	unsigned long int	ret;

	ret = va_arg(arg, unsigned long int);
	return ((long long int)ret);
}

long long int	flag_ll(va_list arg)
{
	unsigned long long int	ret;

	ret = va_arg(arg, unsigned long long int);
	return ((unsigned long long int)ret);
}

long long int	get_type_by_modifier(t_spec *spec, va_list arg)
{
	if (FLAG_H == spec->flag)
		return (flag_h(arg));
	if (FLAG_HH == spec->flag)
		return (flag_hh(arg));
	if (spec->flag == FLAG_LONG)
		return (flag_l(arg));
	if (FLAG_LLONG == spec->flag)
		return (flag_ll(arg));
	return (no_flag(arg));
}
