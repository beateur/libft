/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:58:14 by bihattay          #+#    #+#             */
/*   Updated: 2018/11/29 07:08:10 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		checkerror(char **str, int i)
{
	int		j;
	int		k;

	k = 0;
	if ((i % 5 == 0) && (str[0] != '\0'))
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '.' && str[i][j] != '#')
				return (0);
			j++;
		}
		if ((strlen(str[i]) != 4) && (i % 5 != 0))
			return (0);
		i++;
	}
	if (!checkform(str, i))
		return (0);
	return (1);
}

int		ft_read(char **tab, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(tab = (char **)malloc(sizeof(char *) * 10000)))
		return (0);
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strcpy(tab[i], line);
		if ((i % 4 == 0) && (!checkerror(tab, i)))
			return (0);
		i++;
	}
	return (1);
}
