/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:01:45 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 03:55:40 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
	else
		return (ft_memcmp(s1, s2, ft_strlen(s2)));
	return (0);
}
