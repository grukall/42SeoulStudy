CC = cc
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS =	pipex_bonus.c			\
		pipex_utils_bonus.c		\
		find_file_bonus.c		\
		child_bonus.c			\

GNL_SRCS =	$(GNL_DIR)/get_next_line.c			\
			$(GNL_DIR)/get_next_line_utils.c	\

BONUS_SRCS = pipex_bonus.c

GNL_OBJS = $(GNL_SRCS:%.c=%.o)
OBJS =	$(SRCS:%.c=%.o)
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJS) $(GNL_OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -o pipex -L$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re:
	make fclean
	make all

.PHONY: all clean fclean re