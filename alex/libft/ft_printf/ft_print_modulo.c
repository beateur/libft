/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modulo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:59:33 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 05:14:37 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char		*print_modulo(t_spec *spec, va_list arg)
{
	char	*conv;

	(void)arg;
	conv = ft_strdup("%");
	if (spec->champ > 1)
		gestion_champ(spec, &conv);
	return (conv);
}
