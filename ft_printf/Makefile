NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
cc = gcc
AR = ar rc
RM = rm -f

SRCS = ft_printf.c print_char.c print_d.c print_num.c print_p.c print_u.c print_x.c print_perc.c flag_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		cd libft && make
		cp ./libft/libft.a ${NAME}
		${AR} $@ $^

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	cd libft && make clean

fclean:
	${RM} ${NAME}
	cd libft && make fclean

re: fclean all
