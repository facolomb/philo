SRCS	= main.c init.c utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= philo

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			${RM} a.out

re :		fclean all

.PHONY:		all clean fclean re
