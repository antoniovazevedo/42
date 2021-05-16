SRCS	= dictionary.c dictionary_entries.c validation.c file_utils.c string_utils.c print_numbers.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc 
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re