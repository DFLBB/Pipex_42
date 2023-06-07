NAME		= 	libft.a

SRCS		= 	ft_strlen.c \
				ft_strjoin.c \
				ft_strncmp.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_free.c \
				ft_word_count.c

OBJS		= 	$(SRCS:.c=.o)

AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			= 	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re