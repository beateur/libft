/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:51:24 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 11:02:45 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char		*convert_p(t_spec *spec, va_list arg)
{
	char	*conv;
	void	*ret;

	ret = va_arg(arg, void *);
	if (!ret && spec->precis)
		conv = ft_strdup("0x0");
	else
		conv = ft_strdup("0x");
	conv = ft_strjoinfree(conv, itoa_base((long long)ret, 16, ALNUM), 3);
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	return (conv);
}
