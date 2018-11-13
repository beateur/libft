/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 04:25:44 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 07:26:11 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(*ret) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < (int)ft_strlen(s1))
			ret[i] = s1[i];
		else if (j < (int)ft_strlen(s2))
		{
			ret[i] = s2[j];
			j++;
		}
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
