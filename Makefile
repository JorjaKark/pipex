OUT = pipex

SRC = pipex.c utils.c execute.c checks.c errors.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft
#cc -Wall -Wextra -Werror -g pipex.c utils.c execute.c libft/libft.h libft/ft_strjoin.c libft/ft_split.c libft/ft_strlen.c printf/ft_printf.h printf/ft_printf.c printf/ft_printf2.c

#valgrind --leak-check=full --trace-children=yes
#valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./pipex file1 "ls -l" "wc -l" file2
.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(OUT): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${OUT}

all:	${OUT}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re
