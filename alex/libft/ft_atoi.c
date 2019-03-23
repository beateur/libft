/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:05:47 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:05:50 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int n;
	int nb;

	n = 1;
	nb = 0;
	if (*nptr == '\200')
		return (0);
	while ((*nptr <= ' ' || *nptr == 127) && *nptr != '\e')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	return (nb * n);
}
