CC = cc
FT_PRINTF_DIR = ./ft_printf
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS =	push_swap.c					\
		push_swap_utils.c			\
		stack_functions1.c			\
		stack_functions2.c			\
		stack_functions3.c			\
		sort.c						\
		before_push_swap.c			\
		before_push_swap2.c			\
		stack_top_b_is_biggest.c	\
		parsing.c					\
		Error.c						\
		before_sort.c				\
		quick_sort.c				\

OBJS =	$(SRCS:%.c=%.o)

FT_PRINTF = libftprintf.a

all: $(FT_PRINTF) $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(FT_PRINTF_DIR)/$(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o push_swap -L$(FT_PRINTF_DIR) -lftprintf

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean:
	make clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF_DIR)/$(FT_PRINTF)
	rm -f $(FT_PRINTF_DIR)/libft/libft.a

re:
	make fclean
	make all

.PHONY: all clean fclean re