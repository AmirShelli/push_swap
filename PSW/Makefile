LIBFT = ./libft/libft.a

NAME = push_swap

SRCS =  $(wildcard ./src/*.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./inc 

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C ./libft
	$(CC) $(LIBFT) $(INCLUDES) $(OBJS) -o $(NAME)

clean :
	rm -rf $(wildcard ./*.o)
	rm -rf $(wildcard ./*/*.o)
	rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all