# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/30 16:11:57 by emartin-          #+#    #+#              #
#    Updated: 2020/11/10 17:37:39 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		printf.a

SRCS =		ft_check_flags.c \
			ft_count.c \
			ft_write_cases.c \
			ft_putnbr_global.c \
			ft_printf.c \
			ft_libft_one.c \
			ft_libft_puts.c \
			ft_putstr_global.c \
			ft_putchar_global.c \
			ft_puthex_global.c \
			ft_putpoint_global.c \
			ft_putunsigned_global.c
          
GCC         =   @gcc -Wall -Wextra -Werror
OBJS        =   $(SRCS:.c=.o)
INCLUDES    =   ./

all: $(NAME)

$(NAME):    $(SRCS) ft_printf.h
		$(GCC) -I$(INCLUDES) -c $(SRCS)
		-@ar rc $(NAME) $(OBJS)
		-@ranlib $(NAME)
clean:
		-@$(RM) $(OBJS)
fclean:     clean
		-@$(RM) $(NAME)
re:         fclean all
.PHONY:     all clean fclean