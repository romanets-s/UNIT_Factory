NAME = fdf
SRC = main.c get_next_line.c change_poz.c min_lib.c min_lib_2.c mlx_and_pix.c draw.c color.c
SRCO = $(SRC:.c=.o)
iNCLUDES = fdf.h
FLAGS = -Wall -Wextra -Werror
FW = -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft && \
	gcc $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(FW) 

.c.o:
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRCO)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
