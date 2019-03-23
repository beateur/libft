/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:14:59 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:14:59 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcreate(size_t size, char c)
{
	char	*array;

	if (!(array = ft_strnew(size)))
		return (NULL);
	ft_memset(array, c, size);
	return (array);
}
