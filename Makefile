NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = srcs
SRCS = $(addprefix $(SRCSDIR)/, pipex.c utils_strings_1.c utils_strings_2.c utils_split.c)
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

TESTFILEIN = testfile1.txt
TESTFILEOUT = testfile2.txt
TESTARGS = $(TESTFILEIN) "cat" "wc -l" "wc -l" "cat" $(TESTFILEOUT)

test: fclean
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	./$(NAME) $(TESTARGS)
	cat $(TESTFILEOUT)

.PHONY: all clean fclean re