NAME = so_long

SRC = so_long.c\
parse_1.c\
parse_2.c\
record_list.c\
image_init.c\
commands.c\
render_map.c\
ft_split_with_msg.c\
libft.c\
list_funcs.c\
messages.c


HEADER = solong.h
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror


%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c -o $@ $<


$(NAME): $(OBJ)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^ 

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re