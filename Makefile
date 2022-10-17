SRCS =	ft_printf.c \
		ft_formats.c \
		ft_printf_utils.c \
		ft_print_hex.c \
		ft_print_addr.c
		
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

.c.o:

			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			ar -rc $(NAME) $(OBJS)

clean:
			${RM} ${OBJS} 

fclean: clean
			${RM} ${NAME}

re: fclean all
