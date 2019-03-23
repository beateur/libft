# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 21:14:05 by achiu-au          #+#    #+#              #
#    Updated: 2019/02/16 00:42:52 by achiu-au         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME    = checker
 
 NAME2   = push_swap
 
 CC      =   gcc

CFLAGS  =  -Wall -Wextra -Werror

SRCS    =   ft_action_p.c ft_action_r.c ft_action_rr.c ft_action_swap.c\
             ft_checker.c ft_print_piles.c start.c parsing.c ft_tri_utils.c

SRCS2    = 	ft_action_p.c ft_action_r.c ft_action_rr.c ft_action_swap.c\
             ft_push_swap.c ft_print_piles.c start.c parsing.c ft_tri_3.c ft_tri_5.c\
			 ft_tri.c ft_tri_utils.c

LIBFT   =   libft/

OBJS    = $(SRCS:%.c=%.o)
OBJS2    = $(SRCS2:%.c=%.o)

all:        $(NAME)  $(NAME2);
$(NAME):    $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)libft.a

$(NAME2):    $(OBJS2)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) $(LIBFT)libft.a

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean:
	@/bin/rm -rf $(OBJS) $(OBJS2)
	@make -C $(LIBFT) clean
 
fclean:     clean
	@/bin/rm -rf checker push_swap
	@make -C $(LIBFT) fclean
 
re: fclean all
