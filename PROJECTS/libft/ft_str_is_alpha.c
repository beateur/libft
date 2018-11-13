/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:31:59 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 14:33:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(const char *pdtr)
{
	char	*str;

	str = (char *)pdtr;
	while (*str)
	{
		if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
