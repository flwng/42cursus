NAME = cub3d 
HEADER = cub3d.h
CFLAGS = -Wall -Wextra -Werror
cc = gcc
RM = rm -f

SRCS = $(wildcard *.c) ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	cd libft && make bonus
	cd mlx && make
	cp ./mlx/libmlx.dylib .
	${CC} ./libft/libft.a -Lmlx -lmlx ./libmlx.dylib -framework OpenGL -framework AppKit -o $@ $^

clean:
	${RM} ${OBJS}
	cd libft && make clean
	cd mlx && make clean

fclean:
	${RM} ${NAME} ${OBJS}
	cd libft && make fclean
	cd mlx && make clean
	rm -f ./libmlx.dylib

re: fclean all
