/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:12:34 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/13 10:53:36 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*ret;
	int		j;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	j = 0;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (len <= 0)
		len = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * len + 1)))
		return (NULL);
	s += i;
	i = 0;
	while (i < len)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
