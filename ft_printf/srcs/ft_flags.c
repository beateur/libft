/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 06:13:14 by bihattay          #+#    #+#             */
/*   Updated: 2019/01/17 08:07:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*find_flag(t_struct *new_elem, const char *format_id)
{
	char	*opt;

	opt = (char *)format_id;
	while (find_char(*opt, FLAGS)) // la fonction renvoie 1 si le char *opt est trouver dans FLAGS predefinie dans le .h
	{
		// important que faire dans quel ordre ?
	}
	return (opt);
}
