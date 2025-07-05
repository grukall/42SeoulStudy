SRCS	= main.c cal.c ft_atoi.c ft_putnbr.c
OBJS	= main.o cal.o ft_atoi.o ft_putnbr.o
NAME	= do-op

all: ${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

clean:
