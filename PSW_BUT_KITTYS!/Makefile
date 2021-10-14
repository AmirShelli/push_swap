NAME = push_swap
CHECKER = checker

SRCS =  $(shell find src -type f -name "*.c")
CHECKER_SRCS =  bonus/checker.c src/init.c src/parser.c src/utils.c src/stack.c src/moves/pick.c src/moves/moves.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

INCLUDES = -I ./inc -I ./libft/main_libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LINK_LIBFT = -L./libft/main_libft -lft

all : libft $(NAME)

libft:
	@$(MAKE) all -sC ./libft/main_libft

$(NAME): $(OBJS)
	@$(CC) $(INCLUDES) $(OBJS) $(LINK_LIBFT) -o $(NAME)

bonus: libft $(CHECKER_OBJS)
	@$(CC) $(INCLUDES) $(CHECKER_OBJS) $(LINK_LIBFT) -o $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -sC ./libft/main_libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all libft clean fclean re