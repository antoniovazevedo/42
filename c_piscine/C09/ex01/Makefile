SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
INCDIR	= includes
NAME	= libft.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re