/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:20:37 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:20:38 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*get_fd(t_fd **list, const int fd)
{
	t_fd	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((tmp = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->stock = ft_strdup("");
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*list;
	t_fd			*this;
	char			*buff;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, "", 0) < 0 ||
								!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	this = get_fd(&list, fd);
	this->stock = ft_strcut(this->stock, 0, ft_index(this->stock, '\n') + 1);
	while (!ft_strchr(buff, '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		this->tmp = ft_strjoin(this->stock, buff);
		free(this->stock);
		this->stock = ft_strdup(this->tmp);
		free(this->tmp);
	}
	ret = ft_strchr(this->stock, '\n') ? 1 : ret;
	*line = ft_strsub(this->stock, 0, ft_index(this->stock, '\n'));
	free(buff);
	if (ft_strlen(*line) == 0 && ret == 0)
		return (0);
	return (1);
}
