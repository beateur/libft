/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:08:04 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 11:09:19 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = -1;
	if (!(ret = (char *)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	while (++i < size + 1)
		ret[i] = '\0';
	return (ret);
}
