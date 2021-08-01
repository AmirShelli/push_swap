FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . ! -name "ft_lst*.c" -name "*.c")
OBJS = $(SRCS:.c=.o)
HEADER = libft.h
BNS = $(wildcard ft_lst*.c)
BNO = $(BNS:.c=.o)
NAME = libft.a
.PHONY: all clean fclean bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
bonus: $(BNO)
	@make OBJS:="$(OBJS) $(BNO)" $(NAME)
.c.o: $(BNS) $(SRCS)
	gcc $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BNO)
fclean: clean
	rm -f $(NAME)
re: fclean all 
