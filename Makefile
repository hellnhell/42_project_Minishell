# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/12/01 20:21:03 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

SRCS	=   src/main.c              \
			src/read_path.c			\
			src/check_our_implement.c	\
			src/create_elements.c	\
			src/utils.c				\
			src/builtins/echo.c				\
			src/builtins/pwd.c				\
			src/builtins/cd.c				\
			src/builtins/export.c			\
			src/builtins/unset.c				\
			src/builtins/env.c				\
			src/builtins/exit.c		 \
			src/ft_pipes.c	\
			src/save_std.c	\
			src/signals.c	\
			src/iteration.c

LIBFT	= 	libft/libft.a
PRINTF	= 	printf/printf.a
OBJS    =   $(SRCS:.c=.o)
CFLAGS  =   -Wall -Wextra -Werror -g3 #-fsanitize=address

all     :   $(NAME)

$(NAME) :   $(OBJS)
		@$(MAKE) -C libft
		@$(MAKE) -C printf
		@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

clean   :
		@/bin/rm -f $(OBJS)
			@$(MAKE) -C libft clean
			@$(MAKE) -C printf clean

fclean  :   clean
		-@/bin/rm -f $(NAME) $(LIBFT) $(PRINTF) 

re      :   fclean all

.PHONY  :   all clean fclean re