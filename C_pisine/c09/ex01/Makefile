SRCS = srcs/
SRC = $(SRCS)ft_putchar.c $(SRCS)ft_swap.c $(SRCS)ft_putstr.c $(SRCS)ft_strlen.c $(SRCS)ft_strcmp.c
OBJS = $(SRCS)ft_putchar.o $(SRCS)ft_swap.o $(SRCS)ft_putstr.o $(SRCS)ft_strlen.o $(SRCS)ft_strcmp.o
NAME = libft.a
INC = includes/

all: ${NAME}
.c.o: 
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I $(INC)
${NAME}: ${OBJS}	
	ar rc libft.a $^
clean:
	$(RM) $(OBJS)
fclean:
	rm -f ${OBJS}
	rm -f ${NAME}
re: fclean all
