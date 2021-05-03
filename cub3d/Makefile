NAME = cub3D 
HEADER = cub3d.h
CFLAGS = -Wall -Wextra -Werror
cc = gcc
RM = rm -f

SRCS = check.c		draw.c	draw_bonus.c	sprite.c	screenshot.c	floor_ceil.c	get_map.c	main.c	utils2.c	map.c	movement.c	ray_h.c	ray_v.c	ray.c	utils.c	 ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	cd libft && make bonus
	cd mlx && make
	cp ./mlx/libmlx.dylib .
	${CC}  ./libft/libft.a -Lmlx -lmlx ./libmlx.dylib -framework OpenGL -framework AppKit -o $@ $^

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
