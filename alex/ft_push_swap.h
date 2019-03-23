/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:19:43 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/15 21:19:47 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft/libft.h"

# define PILE_A 	1
# define PILE_B 	2
# define LEFT		1
# define RIGHT 		2

# define LIST_CMDS  "sa*sb*ss*pa*pb*ra*rb*rr*rra*rrb*rrr"

typedef struct		s_algo
{
	t_list			*pile_a;
	t_list			*pile_b;
	int				count;
	int				visu;
}					t_algo;
/*
**      utils
*/
void				print_piles(t_algo *algo);
int					check_pile(t_algo *algo);
t_algo				*init_algo(char **numbers);
void				free_algo(t_algo *algo);
t_list				*new_number(t_list *prev, char *number);
int					check_tab(char **list);
int					list_is_valid(t_algo *algo);
int					check_error(char *str);
int					get_max(t_list *tmp);
int					get_min(t_list *tmp);
int					pile_count(t_list *pile, long nb, int sup);
void				indexage(t_list *pile);
void				wait_user(t_algo *algo);
int					len_list(t_list *list);
void				count_err(t_list *list);
void				print_result(t_algo *algo);
/*
**      tri
*/
void				ft_tri_5(t_algo *algo);
void				ft_tri_2(t_algo *algo);
void				ft_tri_3(t_algo *algo);
void				ft_tri_32(t_algo *algo);
void				quick_sort(t_algo *algo);
/*
**      actions
*/
int					action_sa(t_algo *algo, int checker);
int					action_sb(t_algo *algo, int checker);
int					action_ss(t_algo *algo, int checker);
int					action_pa(t_algo *algo, int checker);
int					action_pb(t_algo *algo, int checker);
int					action_ra(t_algo *algo, int checker);
int					action_rb(t_algo *algo, int checker);
int					action_rr(t_algo *algo, int checker);
int					action_rra(t_algo *algo, int checker);
int					action_rrb(t_algo *algo, int checker);
int					action_rrr(t_algo *algo, int checker);
#endif
