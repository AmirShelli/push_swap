NAME = push_swap
CHECKER = checker

SRCS =  $(shell find src -type f -name "*.c")
CHECKER_SRCS =  bonus/checker.c src/prep/utils.c src/prep/parser.c src/prep/stack.c src/moves/pick.c src/moves/moves.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

INCLUDES = -I ./inc 

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LINK_LIBFT = -L./libft -lft

all : libft $(NAME) bonus

libft:
	@$(MAKE) all -sC ./libft

$(NAME): $(OBJS)
	@$(CC) $(INCLUDES) $(OBJS) $(LINK_LIBFT) -o $(NAME)

bonus: $(CHECKER_OBJS)
	@$(CC) $(INCLUDES) $(CHECKER_OBJS) $(LINK_LIBFT) -o $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -sC ./libft
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)

re : fclean all

.PHONY: all libft clean fclean re