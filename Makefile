NAME = so_long

SRC = solong.c\
messages.c\
ft_split.c\
libft.c\
parse.c\
func_list.c\
temporary_func.c

HEADER = solong.h
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror


%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c -o $@ $<


$(NAME): $(OBJ)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $^ 

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re