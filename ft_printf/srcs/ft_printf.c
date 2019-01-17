/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:59:11 by fberger           #+#    #+#             */
/*   Updated: 2019/01/17 08:08:08 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int   print_non_identifiers(const char *format, const int flen, t_struct *f_id)
{
	static int	index = 0;
	int			lenght;

	lenght = (f_id != NULL) ? f_id->index - index : flen - index;
	if (f_id != NULL)
		ft_putstrsub(format, index, f_id->index);
	else
		ft_putstr(format + index);
	index += lenght;
	if (f_id != NULL)
		index += f_id->padding;
	else
		index = 0;
	return (lenght);
}

int   get_identifiers(const char *format_id, t_struct **f_ids, int index)
{
	t_struct  *new;
	char      *shift;

	if (!(new = create_struct(index)))
		return (0);
	list_push(f_ids, new);
	if (!(shift = find_flag(new, format_id)))
		return (0);
	new->opt = *shift;
	new->shift = 2 + (shift - format_id);
	return (new->shift);
}

int   find_identifiers(const char *format, t_struct **f_ids)
{
	int   index;
	int   tmp;

	index = 0;
	tmp = index;
	while (format && index[format])
	{
		if (!ft_strchr(format + index, '%'))
			return (1);
		index = ft_strchr(format + tmp, '%') - format;
		tmp = index;
		if (!(index += get_identifiers(format + index + 1, f_ids, tmp)))
			return (-1);
	}
	return (1);
}

/*int   print_identifier(t_struct *format_identifiers, va_list ap)
  {
  int   ret;


  ret = 0;

  return (ret);
  }*/

int   ft_printf(const char *format, ...)
{
	va_list     ap;
	t_struct    *format_identifiers;
	t_struct    *begin_list;
	//  const int   flen = ft_strlen(format);
	int         ret;

	format_identifiers = NULL;
	ret = 0;
	if (!find_identifiers(format, &format_identifiers))
	{
		struct_clear(&format_identifiers);
		return (-1);
	}
	va_start(ap, format);
	begin_list = format_identifiers;
	while (format_identifiers != NULL)
	{
		ret += print_non_identifiers(format, ft_strlen(format), format_identifiers);
		ret =+ print_identifier(format_identifiers, ap);
		format_identifiers = format_identifiers->next;
	}
	ret += print_non_identifiers(format, ft_strlen(format), NULL);
	va_end(ap);
	struct_clear(&begin_list);
	return (ret);
}
