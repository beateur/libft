/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:48:28 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:19:00 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_word(const char *s, char c)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (s[len_word] && s[len_word] != c)
		len_word++;
	if (!(word = (char *)malloc(sizeof(char) * len_word + 1)))
		return (NULL);
	ft_strncpy(word, s, len_word);
	word[len_word] = '\0';
	return (word);
}

static int		count_words(const char *s, char c)
{
	int		nbwords;
	int		i;

	i = 0;
	nbwords = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nbwords++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nbwords);
}

char			**ft_strsplit(char const *s, char c)
{
	int		word;
	int		nbwords;
	char	**split;

	nbwords = count_words(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	word = 0;
	while (word < nbwords)
	{
		while (*s && *s == c)
			s++;
		if (!(split[word] = get_word(s, c)))
		{
			while (word-- > 0)
				free(split[word]);
			free(split);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		word++;
	}
	split[word] = NULL;
	return (split);
}
