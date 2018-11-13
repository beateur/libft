/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:16:28 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/11 04:06:11 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			getlen(int n)
{
	int				i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char			*put_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				ns;

	len = getlen(n);
	ns = n;
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n != -2147483648)
	{
		if (n < 0)
			n = n * -1;
		while (len > 0)
		{
			str[len - 1] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
		if (str[0] == '0' && ns != 0)
			str[0] = '-';
	}
	else
		put_min_int(str);
	return (str);
}
