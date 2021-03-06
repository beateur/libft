/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:46:54 by fberger           #+#    #+#             */
/*   Updated: 2018/11/13 18:58:25 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (dest[++i] != '\0')
		;
	while (src[++j] != '\0')
		dest[j + i] = src[j];
	dest[j + i] = '\0';
	return (dest);
}
