NAME = fillit

FLAGS = -Wall -Wextra -Werror

HEADERS = 	fillit.h\
						libft/libft.h\

LIB = libft.a

SOURCES = 	main.c\
						read.c\
									ft_solve.c\


OBJECT = $(SOURCES:.c=.o)

$(NAME): $(LIB)
		@gcc -o $(NAME) $(FLAGS) $(SOURCES) -L./libft/ -lft

all: $(NAME)

$(LIB):
			@make -C libft re


clean:
		@rm -rf $(OBJECT)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
