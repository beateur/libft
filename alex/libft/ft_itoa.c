/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:08:25 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:08:26 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_negatif(int *n, int *negatif, int *len)
{
	if (*n < 0)
	{
		*n *= -1;
		*negatif = 1;
	}
	else
		*negatif = 0;
	*len += *negatif;
}

char		*ft_itoa(int n)
{
	int		len;
	int		tmp;
	int		negatif;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 1;
	while (tmp /= 10)
		len++;
	itoa_negatif(&n, &negatif, &len);
	if ((new = (char *)malloc(len * sizeof(char))) == NULL)
		return (NULL);
	new[len] = '\0';
	while (len--)
	{
		new[len] = n % 10 + '0';
		n /= 10;
	}
	if (negatif)
		new[0] = '-';
	return (new);
}
