/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 02:42:25 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 08:35:27 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int							i;
	long long int				nb;
	int							neg;

	neg = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
			nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\v')
		i++;
	if ((int)ft_strlen(nptr) > 19 + i && ft_str_is_numeric(nptr + i))
		return (-1);
	if (nptr[i] == '-' || nptr[i] == '+')
		neg = (nptr[i++] == '-' ? -1 : 1);
	if ((int)ft_strlen(nptr) > 19 + i && neg == -1 &&
			ft_str_is_numeric(nptr + i))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
}
