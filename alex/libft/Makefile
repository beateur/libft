# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:08:47 by achiu-au          #+#    #+#              #
#    Updated: 2019/02/15 04:56:29 by achiu-au         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strjoinfree.c ft_strcapitalize.c ft_str_reverse.c ft_strcreate.c \
	  ft_intlen.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isintab.c ft_islower.c ft_isprint.c ft_isupper.c \
	  ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putnoctet.c \
	  ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strrchr.c ft_strslen.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	  ft_strtrim.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_strnstr.c \
	  ft_itoa_base.c ft_power.c ft_strisdigit.c ft_atol.c ft_color.c \
	  get_next_line.c ft_strcut.c ft_index.c ft_free_tab.c ft_len_list.c \
	  ft_int_swap.c ft_long_swap.c

FT_PRINTF = ft_printf/ft_printf.c ft_printf/ft_get_specifications.c \
			ft_printf/ft_get_modifiers.c ft_printf/ft_convertion_utils.c \
			ft_printf/ft_convert_c.c ft_printf/ft_convert_d.c ft_printf/ft_convert_f.c \
			ft_printf/ft_convert_o.c ft_printf/ft_convert_p.c ft_printf/ft_convert_s.c \
			ft_printf/ft_convert_u.c ft_printf/ft_convert_x.c ft_printf/ft_print_modulo.c\
			ft_printf/ft_get_modifiers2.c ft_printf/ft_convertion_utils2.c ft_printf/ft_convert_d2.c

SRC += $(FT_PRINTF)

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< 

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)
