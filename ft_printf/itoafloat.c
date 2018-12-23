/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoafloat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:34:36 by alamorth          #+#    #+#             */
/*   Updated: 2018/12/17 20:19:36 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../get-next-line/libft/libft.h"
void	ft_putchar(char c);

long long int		ft_recursive_power(int nb, int power)
{
	int		resultat;

	resultat = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	resultat = nb * ft_recursive_power(nb, power - 1);
	return (resultat);
}

void		itoafloat(double nbr, int **ret)
{
	int		i;
	int		j;
	int		a;
	char	res[32];
	int		k;

	a = 0;
	i = 31;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		**ret += 1;
	}
	while (nbr > 1)
	{
		res[i] = (int)nbr % 10 + 48;
		nbr /= 10;
		i--;
		a++;
	}
	nbr = nbr * ft_recursive_power(10, a);
	nbr -= (long long int)nbr;
	nbr = nbr * ft_recursive_power(10, 6);
	j = i;
	k = j;
	while (j < 31)
	{
		write(1, &res[++j], 1);
		**ret += 1;
	}
	write(1, ".", 1);
	**ret += 1;
	while (nbr > 1)
	{
		res[i] = (int)nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	while (i < k)
	{
		write(1, &res[++i], 1);
		**ret += 1;
	}
}

void	ft_putstr_i(char const *s, int **ret)
{
	int	i;

	i = 0;
	while (s[i])
	{
		**ret += 1;
		ft_putchar(s[i]);
		i++;
	}
}
