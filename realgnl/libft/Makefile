# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bihattay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 12:43:23 by bihattay          #+#    #+#              #
#    Updated: 2018/11/15 08:14:17 by bihattay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

HEADERS = libft.h

NAME = libft.a

SOURCES = ft_atoi.c\
		  ft_bzero.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_memalloc.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strclr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdel.c\
		  ft_strdup.c\
		  ft_strequ.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strncat.c\
		  ft_strnequ.c\
		  ft_strncmp.c\
		  ft_strncpy.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
		  ft_strstr.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_strsub.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_strsplit.c\
		  ft_itoa.c\
		  ft_putchar.c\
		  ft_putstr.c\
		  ft_putendl.c\
		  ft_putnbr.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_strnew.c\
		  ft_lstnew.c\
		  ft_lstdelone.c\
		  ft_lstdel.c\
		  ft_lstadd.c\
		  ft_lstiter.c\
		  ft_lstmap.c\
		  ft_str_is_alpha.c\
		  ft_str_is_numeric.c\
		  ft_list_size.c




OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SOURCES)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -fr $(NAME)

re: fclean all
