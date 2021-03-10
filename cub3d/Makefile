NAME = cub3d 
HEADER = cub3d.h
CFLAGS = -Wall -Wextra -Werror 
cc = gcc
AR = ar -rc
RM = rm -f

SRCS = cub3d.h main.c map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		cd libft && make
		cp ./libft/libft.a ${NAME}
		cd mlx && make
		${AR} $@ $^

%.o: %.c ${HEADER}
	${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit -o -c $< -o $@

clean:
	${RM} ${OBJS}
	cd libft && make clean
	cd mlx && make clean

fclean:
	${RM} ${NAME}
	cd libft && make fclean
	cd mlx && make clean

re: fclean all
