SRCS			=	srcs/push_swap.c srcs/ft_fill_lst.c \
					srcs/move_1.c srcs/move_2.c \
					srcs/move_3.c srcs/ft_sort.c \
					srcs/utils_lst.c srcs/ft_sort_int.c

OBJS			= $(SRCS:.c=.o)

CC				= @gcc
RM				= @/bin/rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

LIBFT			= srcs/libft/libft.a

all:			$(NAME)

$(NAME):		compilation $(OBJS)
				@gcc $(OBJS) $(LIBFT) -o $(NAME)
				@echo "PUSH_SWAP COMPILED"

compilation:
				@make -C srcs/libft

clean:
				@make clean -C srcs/libft
				$(RM) $(OBJS)
				@echo "CLEAN"

fclean:			clean
				@make fclean -C srcs/libft
				$(RM) $(NAME)
				@echo "VERY CLEAN"

re:				fclean $(NAME)