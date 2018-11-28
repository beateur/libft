/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:40:37 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/15 03:24:35 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nbword(char const *str, char c)
{
	int		i;
	int		wordcount;

	i = 0;
	wordcount = 0;
	if (str[0] != c && str && str[i] != '\0')
		wordcount = 1;
	while (str[i + 1])
	{
		if (str[i + 1] != c && str[i] == c)
			wordcount++;
		i++;
	}
	return (wordcount);
}

static char			*getstring(char const *str, int *b, char c)
{
	int		i;
	int		z;
	char	*res;
	int		findumonde;

	z = *b;
	i = 0;
	findumonde = 0;
	while (str[z] == c && str[z])
		z++;
	while (str[z] != c && str[z])
	{
		z++;
		i++;
	}
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (z - i < z)
		res[findumonde++] = str[z - i--];
	res[findumonde] = '\0';
	*b = z;
	return (res);
}

char				**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		b;

	if (!str)
		return (NULL);
	b = 0;
	count = nbword(str, c);
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (i < count)
		tab[i++] = getstring(str, &b, c);
	tab[i] = 0;
	return (tab);
}
