/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:31:28 by bihattay          #+#    #+#             */
/*   Updated: 2018/12/23 05:47:43 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*ft_list_push_back(t_list **list,
		void const *content, int i)
{
	//t_list *nouveau;
	//	t_list *elem;

	/*	if (begin_list == NULL)
		return (0);
		if (!(nouveau = ft_lstnew(content, content_size)))
		return (0);
		if (*begin_list == NULL)
		{
		printf("VOUS ETES ICI");
	 *begin_list = nouveau;
	 }
	 else
	 {
	 elem = *begin_list;
	 while (elem->next != NULL)
	 elem = elem->next;
	 elem->next = nouveau;
	 }*/
	if (!(*list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!((*list)->content= ft_strdup(content)))
	{
		free(*list);
		return (NULL);
	}
	(*list)->index = i;
	return (*list);
}

int				is_tetri_format(char *buf)
{
	int hashtags;
	int i;

	hashtags = 0;
	i = -1;
	while (buf[++i])
	{
		if ((i + 1) == 21 && buf[i] != '\n' && buf[i] != '\0')
		{
			return (0);
		}
		else if ((i + 1) % 5 == 0 && buf[i] != '\n')
		{
			return (0);
		}
		else if ((i + 1) != 21 && (i + 1) % 5 != 0 && buf[i] != '#'
				&& buf[i] != '.')
		{
			return (0);
		}
		else if ((i - 1 >= 0 && buf[i - 1] == '#')
				|| (i + 1 <= 19 && buf[i + 1] == '#')
				|| (i + 5 <= 19 && buf[i + 5] == '#')
				|| (i - 5 >= 0 && buf[i - 5] == '#'))
			hashtags += (buf[i] == '#');
	}
	printf("hashtags is = %d\n", hashtags);
	return ((hashtags == 4 ? 1 : 0));
}

t_list			*parse_input(int fd, t_list **begin_list)
{
	int		i;
	int		ret;
	char	buf[21];
	int		k;
	t_list	*pieces;

	pieces = *begin_list;
	k = 0;
	if ((fd < 0 || read(fd, buf, 0) < 0))
	{
		printf("error is here");
		return (NULL);
	}
	i = -1;
	while ((ret = read(fd, buf, 21)) >= 1)
	{
		buf[ret] = '\0';
		//		printf("\n***\n%s\n***\n", buf);
		if (!(is_tetri_format(buf)) && ++i)
			return (NULL);
		if (*begin_list == NULL)
		{
			*begin_list = ft_list_push_back(&pieces, buf, i);
			pieces = *begin_list;
		}
		else
		{
			pieces->next = ft_list_push_back(&pieces->next, buf, i);
			pieces = pieces->next;
		}
		//	printf("TAMERE");
//		if (k != 0)
		ft_check_width_height(&pieces);
	//	k = 102;
	}
return (*begin_list);
}

void			print_pieces(t_list *pieces)
{
	int		i;
	t_list	*piece;

	printf("entered\n");
	piece = pieces;
	i = 0;
	while (piece)
	{
		printf("pieces[%i] = \n%s\n", i++, piece->content);
		piece = piece->next;
	}
}

int				main(int argc, char **argv)
{
	int		fd;
	t_list	*begin_list;

	//pieces = NULL;
	begin_list = NULL;
	if (argc != 2)// mauvais nbr d'arguments
	{
		ft_putstr_fd("usage: fillit input_file\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	//	if (!(pieces = ft_lstnew("start", 5)))
	//		return (0);
	if ((begin_list = parse_input(fd, &begin_list)) == NULL)// si mauvais format
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	//	ft_solve(&pieces, (ft_sqrt((ft_list_size(pieces) + 1) * 4)));
	print_pieces(begin_list);
	return (1);
}
