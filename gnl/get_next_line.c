/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:20:08 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/23 05:00:39 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "get_next_line.h"
#include "../PROJECTS/libft/libft.h"

#define BUF_SIZE 4096

int		eroor(char **line, int fd, char **buf)
{
	if (!line || fd < 0)
		return (0);
	if (!(*buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	return (1);
}

int		ft_read(int fd, char **ptr, char **buf)
{
	int		ret;
	char	*tmp;
	int		i;

	i = 0;
	while ((res = read(fd, *buf, BUF_SIZE)) > 0)
	{
		tmp = *buf;
		tmp[ret] = '\0';
		tmp = *str;
		if (*str)
			*str = ft_strcat(*str, *buf);
		else
			*str = ft_strdup(*buf);
		ft_memdel((void *)&tmp);
		if (ft_strchr(*str, '\n'))
		{
			ft_memdel((void *)buf);
			return (res);
		}
	}
	ft_memdel((void *)buf);
	return (res);
}

int					fillline(char **line, char **str, int *res)
{
	int				i;
	char			*tmp;

	tmp = *str;
	i = 0;
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
	if (i >= (int)ft_strlen(*str))
		ft_strclr(*str);
	else
		*str = *str + i + 1;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	char		*tmp;
	char		*ptr[10000] = {NULL};
	int			res;
	int			ret;

	if (!eroor(line, fd, &buf))
		return (-1);
	if ((ret = ft_read(fd, &ptr[fd], &buf)) == -1)
		return (-1);
	res = fill(line, &str[fd], &ret);
	return (res);
}
