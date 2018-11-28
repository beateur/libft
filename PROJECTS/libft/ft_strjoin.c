/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:04:40 by alamorth          #+#    #+#             */
/*   Updated: 2018/11/26 20:25:36 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		s1len;
	int		s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = (int)ft_strlen(s1);
	s2len = (int)ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(*ret) * (s1len + s2len + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < (s1len + s2len))
	{
		if (i < s1len)
			ret[i] = s1[i];
		else if (++j < s2len)
			ret[i] = s2[j];
	}
	ret[i] = '\0';
	return (ret);
}
