/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifications.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:43:35 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 11:38:27 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int		flag_dioux(t_spec *spec)
{
	if (spec->type == TYPE_D)
		return (1);
	if (spec->type == TYPE_I)
		return (1);
	if (spec->type == TYPE_O)
		return (1);
	if (spec->type == TYPE_U)
		return (1);
	if (spec->type == TYPE_X)
		return (1);
	if (spec->type == TYPE_XX)
		return (1);
	return (0);
}

static int		get_indics(char format)
{
	if (format == '#')
		return (INDIC_SHARP);
	if (format == '0')
		return (INDIC_ZERO);
	if (format == '-')
		return (INDIC_MIN);
	if (format == ' ')
		return (INDIC_SPACE);
	if (format == '+')
		return (INDIC_PLUS);
	return (0);
}

static int		get_modifier(const char *format)
{
	if (ft_strnequ(format, "ll", 2))
		return (FLAG_LLONG);
	if (ft_strnequ(format, "l", 1))
		return (FLAG_LONG);
	if (ft_strnequ(format, "hh", 2))
		return (FLAG_HH);
	if (ft_strnequ(format, "h", 1))
		return (FLAG_H);
	if (ft_strnequ(format, "L", 1))
		return (FLAG_L);
	return (0);
}

static char		get_type(char format)
{
	if (format == 'c')
		return (TYPE_C);
	if (format == 'p')
		return (TYPE_P);
	if (format == 's')
		return (TYPE_S);
	if (format == 'f')
		return (TYPE_F);
	if (format == 'd')
		return (TYPE_D);
	if (format == 'i')
		return (TYPE_I);
	if (format == 'o')
		return (TYPE_O);
	if (format == 'u')
		return (TYPE_U);
	if (format == 'x')
		return (TYPE_X);
	if (format == 'X')
		return (TYPE_XX);
	if (format == '%')
		return (TYPE_MOD);
	return (-1);
}

const char		*get_specifications(const char *format, t_spec *spec)
{
	while (ft_strchr("#0- +", *format))
		spec->indics |= get_indics(*format++);
	spec->champ = ft_atoi(format);
	format += spec->champ ? ft_intlen(spec->champ) + 1 : 0;
	if (*format == '.')
		spec->precis = ft_atoi(format++ + 1);
	while (*format && ft_isdigit(*format))
		format++;
	spec->flag = get_modifier(format);
	while (ft_strchr("Llh", *format))
		format++;
	if ((spec->type = get_type(*format)) >= 0)
		format++;
	if (INDIC_ZERO & spec->indics && flag_dioux(spec) && spec->precis > 1)
		spec->indics -= INDIC_ZERO;
	if (INDIC_PLUS & spec->indics && INDIC_SPACE & spec->indics)
		spec->indics -= INDIC_SPACE;
	if (INDIC_MIN & spec->indics && INDIC_ZERO & spec->indics)
		spec->indics -= INDIC_ZERO;
	return (format);
}
