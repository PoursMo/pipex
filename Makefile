NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = srcs
SRCS = $(SRCSDIR)/*.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	./pipex testfile1.txt "grep bite" "wc -l" "wc -l" testfile2.txt

.PHONY: all clean fclean re