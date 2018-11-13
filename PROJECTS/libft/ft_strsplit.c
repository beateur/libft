/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:40:37 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 07:47:04 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	endword(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i - 1);
}

static int	nbwords(char const *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	if (str[0] != c && str[0] != '\0')
		nb = 1;
	while (str[i + 1])
	{
		if (str[i + 1] != c && str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**range;
	size_t	i;
	int		j;
	size_t	save;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	if (!((range = (char**)malloc(sizeof(char *) * nbwords(str, c) + 1))))
		return (NULL);
	while (str[++i])
	{
		if (str[i] != c)
		{
			save = i;
			i += endword(str + i, c);
			if ((range[j] =
						(char *)malloc((sizeof(char)) * (i - save))) == NULL)
				return (NULL);
			ft_memcpy(range[j++], str + save, i - save + 1);
		}
	}
	range[j] = 0;
	return (range);
}
