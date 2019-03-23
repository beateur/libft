/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:14:42 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:45:13 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			fill_tab_actions(int (*tab_actions[12])(t_algo *algo,
int checker))
{
	tab_actions[0] = &action_sa;
	tab_actions[1] = &action_sb;
	tab_actions[2] = &action_ss;
	tab_actions[3] = &action_pa;
	tab_actions[4] = &action_pb;
	tab_actions[5] = &action_ra;
	tab_actions[6] = &action_rb;
	tab_actions[7] = &action_rr;
	tab_actions[8] = &action_rra;
	tab_actions[9] = &action_rrb;
	tab_actions[10] = &action_rrr;
}

int				is_action(char *line, char **list_cmds)
{
	int		cmd;

	cmd = 0;
	while (list_cmds[cmd])
	{
		if (ft_strequ(line, list_cmds[cmd]))
			return (cmd);
		cmd++;
	}
	return (-1);
}

static void		print_hit(t_algo *algo)
{
	if (algo->visu)
	{
		print_piles(algo);
		ft_color("hit: ", YELLOW);
	}
}

void			execute_cmds(t_algo *algo, char **list_cmds,
int (*tab_actions[12])(t_algo *algo, int checker))
{
	int		ret;
	char	*line;

	while (1)
	{
		print_hit(algo);
		if ((ret = get_next_line(0, &line)) <= 0)
			break ;
		if (is_action(line, list_cmds) == -1)
		{
			ft_color("Error\n", RED);
			free(line);
			return ;
		}
		tab_actions[is_action(line, list_cmds)](algo, 0);
		free(line);
	}
	free(line);
	print_result(algo);
}

int				main(int ac, char **av)
{
	int		visu;
	int		(*tab_actions[12])(t_algo *algo, int checker);
	char	**list_cmds;
	t_algo	*algo;

	visu = 0;
	if (ac == 1)
		return (1);
	if (ac > 1 && ft_strequ(av[1], "-v"))
		visu = 1;
	if (!(algo = init_algo(av + 1 + visu)))
		return (0);
	else if (!list_is_valid(algo))
	{
		free_algo(algo);
		ft_color("KO\n", RED);
		return (0);
	}
	algo->visu = visu;
	list_cmds = ft_strsplit(LIST_CMDS, '*');
	fill_tab_actions(tab_actions);
	execute_cmds(algo, list_cmds, tab_actions);
	free_algo(algo);
}
