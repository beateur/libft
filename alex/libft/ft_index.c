/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:06:49 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:06:50 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index(const char *str, char c)
{
	int index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
