/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:58:14 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/30 05:49:26 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "../realgnl/libft/libft.h"
#include "../realgnl/get_next_line.h"

int		checktetris(char **str, int i, int *j)
{
	int		k;
	int		flag;

	flag = 0;
	while (++(*j) < i)
	{
		k = -1;
		while (*j == i - 2 && str[*j][++k])
			if (str[*j][k] == '#')
				flag++;
		k = 1;
		while (str[*j][k + 1])
		{
			if (str[*j][k] == '#')
				if ((str[*j][k + 1] == '#') || (str[*j - 1][k] == '#')
						|| (str[*j][k - 1] == '#'))
					flag++;
			k++;
		}
	}
	if (flag != 4)
		return (0);
	return (1);
}

int		checkform(char **str, int i)
{
	int		j;
	int		k;
	int		z;

	j = i - 4;
	z = 0;
	while (++j < i)
	{
		k = 0;
		while (str[j][k])
		{
			if (str[j][k] == '#')
				z++;
			k++;
		}
	}
	if (z != 4)
		return (0);
	j = j - 3;
	if (!checktetris(str, i, &j))
		return (0);
	return (1);
}

int		checkeror(char **str, int i)
{
	int		j;
	int		k;

	j = i - 4;
	if ((i % 5 == 0) && (str[0] != '\0'))
		return (0);
	while (str[j])
	{
		k = 0;
		while (str[j][k])
		{
			if (str[j][k] != '.' && str[j][k] != '#')
			{
		//		printf("%s", str[i]);
			//	printf("%s", str[j]);
				return (0);
			}
			k++;
		}
		if ((ft_strlen(str[j]) != 4) && (i % 5 != 0))
			return (0);
		j++;
	}
	if (!checkform(str, i))
		return (0);
	return (1);
}

int		ft_read(char **tab, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(tab[i] = (char *)ft_memalloc(10000)))
			return (0);
		if (!(tab[i] = strcpy(tab[i], line)))
			return (0);
		i++;
	//	printf("%s\n", line);
	//	write(1, tab[i], ft_strlen(line));
		write(1, "\n", 1);
		if ((i % 4 == 0) && (!checkeror(tab, i)))
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*tab;

	if (!ft_read(&tab, argv[1]))
	{
		printf("TUTUT");
		return (-1);
	}
	return (0);
}
