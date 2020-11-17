# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/11/17 19:30:34 by emartin-         ###   ########.fr        #
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
			src/ft_pipes_alt.c	\
			src/save_std.c
			#src/ft_pipes.c
			#src/clear.c
			
GCC			=   @gcc -Wall -Wextra -Werror -g3
OBJS		=   $(SRCS:.c=.o)
LIBFT		= 	libft/libft.a
PRINTF		= 	printf/printf.a
INCLUDES	=   ./

all: $(NAME)
$(NAME):	$(OBJS)
		@$(MAKE) -C libft
		@$(MAKE) -C printf
		@$(GCC) -I$(INCLUDES) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)
clean:
			-@$(RM) $(OBJS)
			@$(MAKE) -C libft clean
			@$(MAKE) -C printf clean

fclean:		clean
			-@$(RM) $(NAME) $(LIBFT) $(PRINTF) 
			
re:			fclean all
.PHONY:		all clean fclean re bonus
