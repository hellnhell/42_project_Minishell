# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/11/05 21:35:34 by hellnhell        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

SRCS	=   src/main.c              \
			src/read_path.c			\
			src/ft_strjoin_sl.c		\
			src/check_our_implement.c	\
			src/create_elements.c	\
			src/utils.c				\
			src/builtins/echo.c				\
			src/builtins/pwd.c				\
			src/builtins/cd.c				\
			src/builtins/export.c			\
			src/builtins/unset.c				\
			src/builtins/env.c				\
			src/builtins/exit.c

LIBFT   =   libft/libft.a
OBJS    =   $(SRCS:.c=.o)
CFLAGS  = -Wall -Wextra -Werror -I -g3 -ggdb3

$(NAME):    $(OBJS)
		gcc ${CFLAGS} $(OBJS) ${LIBFT} -o $(NAME)
		
$(LIBFT):
		@$(MAKE) -C libft
		
all     : $(NAME)

clean   :
		rm -rf $(OBJS)
		@$(MAKE) -C libft clean
		
fclean  :   clean
		rm -rf $(NAME) $(LIBFT)
		
.PHONY:		all clean fclean re bonus
