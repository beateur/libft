/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:36:32 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/03 09:37:37 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_stock
{
	char			*stockage;
	unsigned short	type;
	struct s_stock	*next;
	struct s_stock	*prev;
	int				index;
}					t_stock;

int				ft_init(t_stock **head);
int				ft_binary(t_stock **head);
t_stock			*ft_create_elem(t_stock **stock, char *data, int i);
int				ft_check(t_stock *stock);
t_stock			*ft_read(char *av, t_stock **head, int *i);

#endif
