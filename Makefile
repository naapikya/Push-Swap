NAME = pushs_swap.a
SRCS = $(shell find "./sources" -name '*.c') push_swap.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar csr

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		${AR} ${NAME} ${OBJS}
		gcc $(NAME) -o push_swap

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean bonus re .c.o
