/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:04:35 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/09 15:26:25 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;
	char	*psrc;

	ptr = dest;
	psrc = (char *)src;
	while (*ptr)
		ptr++;
	while (*psrc)
		*ptr++ = *psrc++;
	*ptr = '\0';
	return (dest);
}
