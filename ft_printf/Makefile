SRCS =  srcs/ft_printf.c \
		srcs/ft_puthexa.c \
		srcs/ft_putstr.c \
		srcs/ft_specifier.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc
CFLAGS = -Werror -Wextra -Wall -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all