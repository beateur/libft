/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:52:15 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 05:35:49 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static long long int	modifier_o_h(va_list arg)
{
	unsigned short	ret;

	ret = va_arg(arg, int);
	return ((long long int)ret);
}

char					*convert_o(t_spec *spec, va_list arg)
{
	long long int	ret;
	char			*conv;
	int				len;

	if (FLAG_H & spec->flag)
		ret = modifier_o_h(arg);
	else
		ret = get_type_by_modifier(spec, arg);
	if (ret)
		conv = itoa_base(ret, 8, ALNUM);
	else
		conv = ft_strdup("0");
	if (!ret && spec->precis == 0)
		*conv = '\0';
	if (INDIC_SHARP & spec->indics)
		conv = ft_strjoinfree("0", conv, 2);
	len = ft_strlen(conv);
	if (spec->precis > len > 0)
	{
		conv = ft_strjoinfree(ft_strcreate(spec->precis - len, '0'), conv, 3);
		len = spec->precis;
	}
	if (spec->champ > len)
		gestion_champ(spec, &conv);
	return (conv);
}
