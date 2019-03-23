/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:50:26 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 11:44:15 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char			*llitoa(long long number)
{
	int		n;
	char	*array;

	n = 0;
	array = ft_strnew(llong_len(number) + (number < 0));
	if (number < 0 && (number = -number))
		array[n++] = '-';
	while (number)
	{
		ft_strncat(array, &ALNUM[(number % 10)], 1);
		number /= 10;
	}
	ft_str_reverse(array + (*array == '-'));
	return (array);
}

int				llong_len(long long int number)
{
	int			len;

	len = 0;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static int		len_for_base(long long n, int base)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*itoa_base(long long number, int base, char *set)
{
	int			n;
	char		*array;

	n = 0;
	array = ft_strnew(sizeof(char) * len_for_base(number, base) +
			(number < 0) + 1);
	if (number < 0 && (number = -number))
		array[n++] = '-';
	while (number)
	{
		ft_strncat(array, &set[number % base], 1);
		number /= base;
	}
	ft_str_reverse(array + (*array == '-'));
	return (array);
}

void			gestion_champ(t_spec *spec, char **conv)
{
	char	c;
	int		tmp;

	c = INDIC_ZERO & spec->indics ? '0' : ' ';
	tmp = ft_strlen(*conv);
	if (INDIC_SHARP & spec->indics && INDIC_ZERO & spec->indics &&
			(spec->type == TYPE_X || spec->type == TYPE_XX))
		*conv = ft_strjoinfree(ft_strcreate(spec->champ - tmp - 2, c),
				*conv, 3);
	else if (INDIC_MIN & spec->indics)
		*conv = ft_strjoinfree(*conv, ft_strcreate(spec->champ - tmp, c), 3);
	else
		*conv = ft_strjoinfree(ft_strcreate(spec->champ - tmp, c), *conv, 3);
}
