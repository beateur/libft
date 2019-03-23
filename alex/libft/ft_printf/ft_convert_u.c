/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:00:36 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 13:37:38 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static unsigned long int	modifier_u_l(va_list arg)
{
	unsigned long int	ret;

	ret = va_arg(arg, unsigned long int);
	return (ret);
}

static unsigned long int	modifier_u_ll(va_list arg)
{
	unsigned long long int	ret;

	ret = va_arg(arg, unsigned long long int);
	return (ret);
}

static int					ullen(unsigned long long number)
{
	int		len;

	len = 0;
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}

static char					*itoa_u(unsigned long number)
{
	char	*array;
	int		n;

	n = 0;
	array = ft_strnew(sizeof(char) * ullen(number) + 1);
	while (number)
	{
		array[n++] = '0' + (number % 10);
		number /= 10;
	}
	array[n] = '\0';
	ft_str_reverse(array);
	return (array);
}

char						*convert_u(t_spec *spec, va_list arg)
{
	long long int	ret;
	char			*conv;
	int				len;

	if (!spec->precis)
		return (ft_strdup(""));
	if (spec->flag == FLAG_LONG || spec->flag == FLAG_LLONG)
	{
		ret = spec->flag == FLAG_LONG ? modifier_u_l(arg) : modifier_u_ll(arg);
		ret ? conv = itoa_u(ret) : 0;
	}
	else
	{
		ret = get_type_by_modifier(spec, arg);
		ret ? conv = llitoa(ret) : 0;
	}
	!ret ? conv = ft_strdup("0") : 0;
	len = ft_strlen(conv);
	if (spec->precis > len)
		conv[spec->precis] = '\0';
	if (spec->precis > len > 0)
		conv = ft_strjoinfree(ft_strcreate(spec->precis - len, '0'), conv, 3);
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	return (conv);
}
