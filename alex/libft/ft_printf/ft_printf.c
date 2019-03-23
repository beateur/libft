/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:29:30 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/06 04:07:51 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static void		fill_conv_tab(char *(*tab_conv[11])(t_spec *spec, va_list arg))
{
	tab_conv[0] = &convert_c;
	tab_conv[1] = &convert_s;
	tab_conv[2] = &convert_p;
	tab_conv[3] = &convert_d;
	tab_conv[4] = &convert_d;
	tab_conv[5] = &convert_o;
	tab_conv[6] = &convert_u;
	tab_conv[7] = &convert_x;
	tab_conv[8] = &convert_x;
	tab_conv[9] = &convert_f;
	tab_conv[10] = &print_modulo;
}

static void		reset_spec(t_spec *spec)
{
	spec->precis = -1;
	spec->champ = 0;
	spec->indics = 0;
	spec->flag = 0;
	spec->type = -1;
}

void			ft_douille(t_spec *spec, va_list arg,
		char *(*tab_conv[11])(t_spec *spec, va_list arg), const char *format)
{
	int i;

	i = 0;
	while (1)
	{
		if (!format[i] || format[i] == '%')
		{
			spec->line = ft_strjoinfree(spec->line, ft_strsub(format, 0, i), 3);
			if (!format[i++])
				break ;
			format += i;
			reset_spec(spec);
			format = get_specifications(format, spec);
			if (spec->type >= 0)
			{
				spec->line = ft_strjoinfree(spec->line,
					tab_conv[spec->type](spec, arg), 3);
			}
			i = -1;
		}
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	char		*(*tab_conv[11])(t_spec *spec, va_list arg);
	t_spec		*spec;
	int			i;
	va_list		arg;

	if (!(spec = (t_spec *)malloc(sizeof(t_spec))))
		return (0);
	spec->count = 0;
	spec->line = ft_strnew(1);
	fill_conv_tab(tab_conv);
	va_start(arg, format);
	ft_douille(spec, arg, tab_conv, format);
	i = ft_strlen(spec->line) - spec->count;
	va_end(arg);
	ft_putstr(spec->line);
	free(spec->line);
	free(spec);
	return (i);
}
