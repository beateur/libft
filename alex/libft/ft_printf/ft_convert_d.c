/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:53:46 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 13:34:06 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static long long int	modifier_d_h(va_list arg)
{
	short int		ret;

	ret = va_arg(arg, int);
	return ((long long int)ret);
}

static long long int	modifier_d_hh(va_list arg)
{
	signed char		ret;

	ret = va_arg(arg, int);
	return ((long long int)ret);
}

static long long int	get_modifier_d(t_spec *spec, va_list arg)
{
	if (FLAG_H & spec->flag)
		return (modifier_d_h(arg));
	else if (FLAG_HH & spec->flag)
		return (modifier_d_hh(arg));
	else if (FLAG_LONG & spec->flag)
		return (flag_l(arg));
	else if (FLAG_LLONG & spec->flag)
		return (flag_ll(arg));
	return (no_flag_signed(arg));
}

static char				*convert_d2(t_spec *spec, long long int ret)
{
	char	*conv;

	if (ret <= LONG_MIN || ret >= LONG_MAX)
		conv = ulitoa(ret);
	else if (ret)
		conv = llitoa(ret >= 0 ? ret : -ret);
	else
		conv = ft_strdup("0");
	if (!ret && spec->precis == 0)
		*conv = '\0';
	return (conv);
}

char					*convert_d(t_spec *spec, va_list arg)
{
	long long int	ret;
	char			*conv;
	int				len;

	ret = get_modifier_d(spec, arg);
	conv = convert_d2(spec, ret);
	len = ft_strlen(conv);
	if (spec->precis > len - (ret < 0) > 0)
		conv = ft_strjoinfree(ft_strcreate(spec->precis - len, '0'),
				conv, 3);
	if (ret < 0)
		conv = ft_strjoinfree("-", conv, 2);
	if (INDIC_PLUS & spec->indics && ret >= 0)
		conv = ft_strjoinfree("+", conv, 2);
	if (INDIC_SPACE & spec->indics && ret >= 0)
		conv = ft_strjoinfree(" ", conv, 2);
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	if (INDIC_ZERO & spec->indics)
		replace_sign(conv, (ret < 0 ? '-' : '+'));
	if (INDIC_ZERO & spec->indics && INDIC_SPACE & spec->indics &&
			spec->champ + 1 > (int)ft_strlen(conv))
		replace_sign(conv, ' ');
	return (conv);
}
