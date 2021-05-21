SRCS			=	srcs/check_1.c \
					srcs/check_2.c \
					srcs/check_half_rank.c \
					srcs/check_is_in_quarter_rank.c \
					srcs/check_is_quarter_list.c \
					srcs/fill_list.c \
					srcs/move.c \
					srcs/move_2.c \
					srcs/move_3.c \
					srcs/not_rank_sort.c \
					srcs/push_swap.c \
					srcs/random_norme.c \
					srcs/rank_list.c \
					srcs/ranksort_1.c \
					srcs/ranksort_2.c \
					srcs/ranksort_3.c \
					srcs/bestsort.c \
					srcs/utilis.c

OBJS			= $(SRCS:.c=.o)

CC				= @gcc
RM				= @/bin/rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

LIBFT			= libft/libft.a

all:			$(NAME)

$(NAME):		compilation $(OBJS)
				@gcc $(OBJS) $(LIBFT) -o $(NAME)
				@echo "PUSH_SWAP COMPILED"

compilation:
				@make -C libft

clean:
				@make clean -C libft
				@$(RM) $(OBJS)

fclean:			clean
				@make fclean -C libft
				@$(RM) $(NAME)

re:				fclean $(NAME)