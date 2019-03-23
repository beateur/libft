/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_modifier2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:35:02 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 05:38:32 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

long long int	no_flag_signed(va_list arg)
{
	signed int	ret;

	ret = va_arg(arg, int);
	return ((long long int)ret);
}

long long int	no_flag(va_list arg)
{
	unsigned int	ret;

	ret = va_arg(arg, unsigned int);
	return ((long long int)ret);
}
