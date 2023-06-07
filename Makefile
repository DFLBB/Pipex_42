#Exit
NAME		= 	pipex

#Sources
SRCS		= 	pipex.c \
				p_functions.c

# Bonus
 BONUS_SRCS	=	pipex_bonus.c \
 				p_functions_bonus.c \
 				p_exec_bonus.c

OBJS		= 	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

NAME_BONUS	=	pipex_bonus

#Compilation
# Linking: option -r to ensure that if the library (.a) file already exists, 
# it will be replaced. The command option -c should be used so that if the 
# file doesn’t exist, it will be created.
AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

#Erase
RM			= 	rm -rf

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

#Default target
all:		$(LIBFT) $(NAME)
bonus: 		$(LIBFT) $(NAME_BONUS)

$(LIBFT):
			@make -C libft

$(NAME):	$(OBJS) $(LIBFT_SRC)$(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

$(NAME_BONUS): 		$(BONUS_OBJS) $(LIBFT_SRC)$(LIBFT)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)
			
#Cleaning objects (Eliminacion de objetos)
clean:
			$(RM) $(NAME) $(OBJS) $(NAME_BONUS) $(BONUS_OBJS)

#Cleaning objects and executable 
fclean:		clean
			@make -C libft fclean

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all clean fclean bonus re