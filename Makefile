NAME = bsq
SRC = bsq.c create_t_map.c find_bsq.c freeing.c ft_atoi.c ft_strlen.c funcs.c map_good.c map_preparation.c std_in.c zero_args.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
.PHONY: all clean fclean
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)