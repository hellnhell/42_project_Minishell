SRCSC		= ft_memset.c \
				ft_bzero.c \
				ft_memmove.c \
				ft_memcpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_strcpy.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_split.c \
				get_next_line/get_next_line.c \
				ft_strcmp.c \
				ft_split_list.c \
				ft_split_list_cpy.c \
				ft_split_list_found.c \
				ft_split_list_skip.c \
				ft_strpncpy.c	\
				list_add_elements.c \
				list_pop_elements.c \
				list_utils.c	\
				list_utils2.c
			
SBONUS		= ft_lstadd_front_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstmap_bonus.c\

SRCSH		= libft.h

OBJS		= $(SRCSC:%.c=%.o)

OBONUS		= $(SBONUS:%.c=%.o)

NAME		= libft.a

CC			= @gcc

AR			= ar rc

RM			= @rm -f

CFLAGS		= -Wall -Wextra -Werror -g3

$(NAME):	${OBJS}
	-@${AR} ${NAME} ${OBJS} ${SRCSH} 


all:		${NAME}

clean:
			${RM} ${OBJS} ${OBONUS} 


fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		all ${OBONUS}
	-@${AR} ${NAME} ${OBJS} ${OBONUS}


.PHONY:		all clean fclean re
