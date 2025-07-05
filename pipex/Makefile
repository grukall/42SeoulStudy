CC = cc
LIBFT_DIR = ./libft
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS =	pipex.c			\
		pipex_utils.c	\
		find_file.c		\

OBJS =	$(SRCS:%.c=%.o)
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o pipex -L$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re:
	make fclean
	make all

.PHONY: all clean fclean re