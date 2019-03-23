/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:56:28 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 11:05:56 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static void		round_decimal(int i, char **conv)
{
	char	*decimal;

	decimal = *conv;
	if (decimal[i] > '5')
	{
		decimal[i--] = '0';
		decimal[i]++;
		if (decimal[i] > '9')
			round_decimal(i, conv);
	}
}

static char		*get_decimal(t_spec *spec, float ret)
{
	char	*conv;
	char	c[2];

	c[1] = '\0';
	conv = ft_strdup("");
	while (ret)
	{
		ret *= 10;
		*c = '0' + (long long)ret;
		conv = ft_strjoinfree(conv, c, 1);
		ret -= (long long)ret;
	}
	round_decimal(spec->precis, &conv);
	conv[spec->precis] = '\0';
	return (conv);
}

static char		*convert_f_long_double(t_spec *spec, va_list arg)
{
	long double		ret;
	char			*conv;

	ret = va_arg(arg, long double);
	if (ret > 0 && INDIC_PLUS & spec->indics)
		conv = ft_strdup("+");
	else if (ret < 0 && (ret - ret))
		conv = ft_strdup("-");
	else
		conv = ft_strdup("");
	if (ret >= 0 && INDIC_SPACE & spec->indics)
		conv = ft_strjoinfree(" ", conv, 2);
	if (ret < 0 && (ret = -ret))
		conv = ft_strjoinfree("-", conv, 2);
	conv = ft_strjoinfree(conv, llitoa((long long)ret), 3);
	if (spec->precis != 0)
		conv = ft_strjoinfree(conv, ".", 1);
	conv = ft_strjoinfree(conv,
			get_decimal(spec, ret - (long long)ret), 3);
	return (conv);
}

static char		*convert_f_float(t_spec *spec, va_list arg)
{
	float		ret;
	char		*conv;

	ret = va_arg(arg, double);
	if (ret > 0 && INDIC_PLUS & spec->indics)
		conv = ft_strdup("+");
	else if (ret < 0 && (ret - ret))
		conv = ft_strdup("-");
	else
		conv = ft_strdup("");
	if (ret >= 0 && INDIC_SPACE & spec->indics)
		conv = ft_strjoinfree(" ", conv, 2);
	if (ret < 0 && (ret = -ret))
		conv = ft_strjoinfree("-", conv, 2);
	conv = ft_strjoinfree(conv, llitoa((long long)ret), 3);
	if (spec->precis != 0)
		conv = ft_strjoinfree(conv, ".", 1);
	conv = ft_strjoinfree(conv,
			get_decimal(spec, ret - (long long)ret), 3);
	return (conv);
}

char			*convert_f(t_spec *spec, va_list arg)
{
	int		len;
	char	*conv;

	len = 0;
	spec->precis = spec->precis < 0 ? 6 : spec->precis;
	if (FLAG_L & spec->flag)
		conv = convert_f_long_double(spec, arg);
	else
		conv = convert_f_float(spec, arg);
	if (spec->precis > 0)
		len = ft_strlen(ft_strchr(conv, '.') + 1);
	if (len >= 0 && spec->precis > len)
		conv = ft_strjoinfree(conv, ft_strcreate(spec->precis - len, '0'), 2);
	if ((int)ft_strlen(conv) < spec->champ)
		gestion_champ(spec, &conv);
	return (conv);
}
