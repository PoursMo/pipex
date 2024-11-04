NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft -g
SRCSDIR = srcs
SRCS = $(addprefix $(SRCSDIR)/, pipex.c utils_parse.c utils_path.c utils_other.c utils_tries_1.c utils_tries_2.c)
OBJS = $(SRCS:.c=.o)
BONUSDIR = bonus
BONUSSRCS = $(addprefix $(BONUSDIR)/, pipex_bonus.c utils_parse_bonus.c utils_path_bonus.c utils_other_bonus.c utils_tries_1_bonus.c utils_tries_2_bonus.c)
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

bonus: 

bonusclean:

bonusfclean:

bonusre:

.PHONY: all clean fclean re