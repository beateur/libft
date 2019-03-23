/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:59:33 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 10:37:11 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static long long	get_modifier_x(t_spec *spec, va_list arg)
{
	unsigned char	ret;

	if (FLAG_HH & spec->flag)
	{
		ret = va_arg(arg, signed int);
		return (ret);
	}
	return (get_type_by_modifier(spec, arg));
}

char				*convert_x(t_spec *spec, va_list arg)
{
	long long	ret;
	char		*conv;
	int			len;

	if (!(ret = get_modifier_x(spec, arg)))
		conv = ft_strdup("0");
	else
		conv = itoa_base(ret, 16, ALNUM);
	len = ft_strlen(conv);
	if (spec->precis > len)
		conv = ft_strjoinfree(ft_strcreate(spec->precis - len, '0'), conv, 3);
	if (!ret && spec->precis == 0)
		*conv = '\0';
	if (ret && INDIC_SHARP & spec->indics && !(INDIC_ZERO & spec->indics))
		conv = ft_strjoinfree("0x", conv, 2);
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	if (ret && INDIC_SHARP & spec->indics && INDIC_ZERO & spec->indics)
		conv = ft_strjoinfree("0x", conv, 2);
	if (spec->type == TYPE_XX)
		ft_strcapitalize(conv);
	return (conv);
}
