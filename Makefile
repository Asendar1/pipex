SRC_DIR = sources/
SRC_FILES = main.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT = -Llibft -lft

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re