/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:14:28 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/28 04:53:04 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkerror(int fd, char **line, char **buf)
{
	if (fd < 0 || !line)
		return (0);
	if (!(*buf = (char *)ft_strnew(BUFF_SIZE)))
		return (0);
	return (1);
}

int		kiride(int fd, char **str, int i, char **buf)
{
	int		res;
	char	*tmp;

	while ((res = read(fd, *buf, BUFF_SIZE)) > 0 && ++i > -1)
	{
		tmp = *buf;
		tmp[res] = '\0';
		tmp = *str;
		if (*str)
			*str = ft_strjoin(*str, *buf);
		else
			*str = ft_strdup(*buf);
		if (i > 0)
			ft_strdel(&tmp);
		if ((*str != NULL) && (ft_strchr(*str, '\n')))
		{
			ft_strdel(buf);
			return (res);
		}
		if (*str == NULL)
			return (-1);
	}
	ft_strdel(buf);
	return (res);
}

int		kirenpli(char **line, char **str, int *res)
{
	int		i;
	char	*tmp;

	tmp = *str;
	i = 0;
	if (!tmp)
		return (-1);
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (i == 0 || tmp[0] == '\0')
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	else if (!(*line = ft_strsub(tmp, 0, i)))
		return (-1);
	if (!ft_strlen(*str) && *res == 0)
		return (0);
	if (i == (int)ft_strlen(*str))
		*str = *str + i;
	else
		*str = *str + i + 1;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[4867] = {NULL};
	int			res;
	char		*buf;
	int			i;
	int			ret;

	i = -1;
	ret = fd;
	if (!(checkerror(fd, line, &buf)))
		return (-1);
	if ((res = kiride(fd, &str[fd], i, &buf)) == -1)
	{
		if (buf)
			ft_strdel(&buf);
		return (-1);
	}
	ret = kirenpli(line, &str[fd], &res);
	return (ret);
}
