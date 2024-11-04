NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCSDIR = srcs/
SRCS =	$(SRCSDIR)main.c			\
		$(SRCSDIR)pipex.c			\
		$(SRCSDIR)utils_parse.c		\
		$(SRCSDIR)utils_path.c		\
		$(SRCSDIR)utils_other.c		\
		$(SRCSDIR)utils_tries_1.c	\
		$(SRCSDIR)utils_tries_2.c
OBJS = $(SRCS:.c=.o)
BONUSDIR = bonus/
BONUSSRCS = $(BONUSDIR)main.c					\
			$(BONUSDIR)pipex.c					\
			$(BONUSDIR)utils_parse.c			\
			$(BONUSDIR)utils_path.c				\
			$(BONUSDIR)utils_other.c			\
			$(BONUSDIR)utils_tries_1.c			\
			$(BONUSDIR)utils_tries_2.c			\
			$(BONUSDIR)get_next_line.c			\
			$(BONUSDIR)get_next_line_utils.c	\
			$(BONUSDIR)heredoc.c
BONUSOBJS = $(BONUSSRCS:.c=.o)
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

bonus: $(LIB) $(BONUSOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUSOBJS) $(LIB)

bonusclean:
	rm -f $(BONUSSRCS:.c=.o)

bonusfclean: bonusclean
	rm -f $(NAME)

bonusre: bonusfclean bonus

.PHONY: all clean fclean re