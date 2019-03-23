/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:20:15 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:20:18 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

typedef struct		s_fd
{
	int				fd;
	char			*stock;
	char			*tmp;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);
t_fd				*get_fd(t_fd **list, const int fd);

#endif
