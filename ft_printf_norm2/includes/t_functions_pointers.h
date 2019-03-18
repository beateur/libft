/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_functions_pointers.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:00:06 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 20:26:02 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FUNCTIONS_POINTERS_H
# define T_FUNCTIONS_POINTERS_H
# include <string.h>
# include <stdarg.h>
# include "t_options.h"

# define NB_ACCEPTED_OPTIONS (13)

typedef struct			s_func
{
	char	option;
	int		(*function)(t_options*, va_list*);
}						t_functions_pointers;

#endif
