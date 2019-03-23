/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:46:29 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 12:25:49 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define INDIC_SHARP			1
# define INDIC_ZERO				2
# define INDIC_MIN				4
# define INDIC_SPACE			8
# define INDIC_PLUS				16

# define FLAG_H					1
# define FLAG_HH				2
# define FLAG_LONG				4
# define FLAG_LLONG				8
# define FLAG_L					16

# define TYPE_C					0
# define TYPE_S					1
# define TYPE_P					2
# define TYPE_D					3
# define TYPE_I					4
# define TYPE_O					5
# define TYPE_U					6
# define TYPE_X					7
# define TYPE_XX				8
# define TYPE_F					9
# define TYPE_MOD				10

# define ALNUM "0123456789abcdef"

typedef struct		s_spec
{
	char			*line;
	int				precis;
	int				champ;
	char			indics;
	char			flag;
	int				type;
	int				count;
}					t_spec;

int					indic(int a, int b);
int					ft_printf(const char *format, ...);
void				gestion_champ(t_spec *spec, char **conv);
const char			*get_specifications(const char *format, t_spec *spec);
long long int		get_type_by_modifier(t_spec *spec, va_list arg);

char				*llitoa(long long number);
char				*ulitoa(unsigned long number);
char				*itoa_base(long long number, int base, char *set);
int					llong_len(long long int number);
void				replace_sign(char *line, char sign);

long long int		flag_h(va_list arg);
long long int		flag_hh(va_list arg);
long long int		flag_l(va_list arg);
long long int		flag_ll(va_list arg);
long long int		no_flag(va_list arg);
long long int		no_flag_signed(va_list arg);

char				*convert_s(t_spec *spec, va_list arg);
char				*convert_p(t_spec *spec, va_list arg);
char				*convert_c(t_spec *spec, va_list arg);
char				*convert_x(t_spec *spec, va_list arg);
char				*convert_u(t_spec *spec, va_list arg);
char				*convert_o(t_spec *spec, va_list arg);
char				*convert_d(t_spec *spec, va_list arg);
char				*convert_f(t_spec *spec, va_list arg);
char				*print_modulo(t_spec *spec, va_list arg);

#endif
