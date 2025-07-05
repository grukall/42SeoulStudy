CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRCS =	main.c			\
		ft_atoi.c		\
		philo_utils.c	\
		experiment.c	\
		use_mutex.c		\

OBJS =	$(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re