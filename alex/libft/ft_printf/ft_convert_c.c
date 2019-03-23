/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:47:50 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 11:54:38 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char		*convert_c(t_spec *spec, va_list arg)
{
	unsigned char	ret;
	char			*conv;

	if (!(ret = va_arg(arg, int)))
	{
		conv = ft_strdup("^@");
		spec->count++;
		if (spec->champ > 0)
			spec->champ++;
	}
	else
	{
		conv = ft_strnew(1);
		*conv = ret;
	}
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	return (conv);
}
