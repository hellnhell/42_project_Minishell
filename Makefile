# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/12/09 17:37:03 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

SRCS	=   src/builtins/echo.c				\
			src/builtins/pwd.c				\
			src/builtins/cd.c				\
			src/builtins/export.c			\
			src/builtins/export_env.c			\
			src/builtins/unset.c				\
			src/builtins/env.c				\
			src/builtins/exit.c		 \
			\
			src/setups/main.c              \
			src/setups/read_path.c			\
			src/setups/check_our_implement.c	\
			src/setups/create_elements.c	\
			src/setups/utils.c				\
			src/setups/ft_pipes.c	\
			src/setups/ft_redirections.c \
			src/setups/save_std.c	\
			src/setups/signals.c 	\
			src/setups/commands_redi_pipe.c \
			src/setups/create_orders.c \
			src/setups/errors.c
			
GCC			=   gcc -Wall -Wextra -Werror -g3
OBJS		=   $(SRCS:c=o)
LIBFT		= 	libft/libft.a
PRINTF		= 	printf/printf.a
INCLUDES	=   ./

%.o: %.c
	@${GCC} -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
	@echo "\033[0;35mCompiling minishell..."
	@echo "\033[0;34m..."
	@echo "\033[0;36m..."
	@$(MAKE) -C libft
	@$(MAKE) -C printf
	@echo "\033[0;36m..."
	@printf "\033[0;33mGenerating minishell... %-33.33s\r" 
	@$(GCC) -I$(INCLUDES) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)
	@echo "\n\033[0mDone!!!"

	
clean:
	@echo "\033[0;31mDeleting objects..."
	-@$(RM) $(OBJS)
	@$(MAKE) -C libft clean
	@$(MAKE) -C printf clean
	@echo "\033[0m"

fclean:		clean
	-@$(RM) $(NAME) $(LIBFT) $(PRINTF) 
	@echo "\033[0m"
			
re:			fclean all

.PHONY:		all clean fclean re bonus

