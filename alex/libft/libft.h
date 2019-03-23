/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:42:10 by achiu-au          #+#    #+#             */
/*   Updated: 2019/02/16 01:20:25 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "ft_color.h"
# include "get_next_line.h"

typedef struct		s_list
{
	int				index;
	long			number;
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				ft_long_swap(long *a, long *b);
void				ft_int_swap(int *a, int *b);
int					ft_len_list(t_list *list);
void				ft_free_tab(char **tab);
int					ft_index(const char *str, char c);
char				*ft_strcut(char *str, int index, int len);
void				ft_color(char *str, char *color);
void				ft_strcapitalize(char *str);
void				ft_str_reverse(char *str);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnoctet(void *str, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strisdigit(char *str);
int					ft_intlen(int nbr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_atoi(const char *nptr);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strslen(char *str, char *s);
int					ft_isintab(char *s, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(char const *str);
long long			ft_power(long long number, int power);
long int			ft_atol(const char *nptr);
char				*ft_strcreate(size_t size, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
								const char *little, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa_base(int number, int base);
char				*ft_strjoinfree(char *s1, char *s2, int to_free);

#endif
