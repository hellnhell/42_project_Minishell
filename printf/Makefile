# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 16:56:40 by isfernan          #+#    #+#              #
#    Updated: 2020/12/01 17:17:34 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c	ft_printf_utils.c	specifiers_i.c	putchar.c	\
		specifiers_us.c		specifiers_resto.c			putchar_2.c	\
		ft_printf_utils2.c	ft_printf_utils3.c

OBJS = ${SRCS:.c=.o}

NAME = printf.a

$(NAME): 
			-@gcc -Wall -Werror -Wextra -g3 -c $(SRCS)
			-@ar rc $(NAME) $(OBJS)
			-@ranlib $(NAME)

all: $(NAME)

clean:
			-@rm -f $(OBJS)

fclean: 	clean
			-@rm -f $(NAME)

re:	fclean all

.PHONY: all clea fclean re

