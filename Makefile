NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCSDIR = srcs
SRCS = $(addprefix $(SRCSDIR)/, pipex.c utils_parse.c utils_path.c)
OBJS = $(SRCS:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(LIB):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

CMDS = "cat" "head -1"

test: all
	./pipex testfile1.txt $(CMDS) testfile2.txt

.PHONY: all clean fclean re