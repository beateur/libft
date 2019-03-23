/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:21:27 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/07 12:21:20 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void		replace_sign(char *line, char sign)
{
	char	*where;

	if (!(where = ft_strchr(line, sign)))
		return ;
	*where = '0';
	*line = sign;
}
