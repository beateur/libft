/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:06:47 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/16 03:12:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *format, ...);

typedef struct	s_struct
{
	int						index;
	int						padding;
	int			len_data;
	int			ret;
}				t_struct;

#endif
