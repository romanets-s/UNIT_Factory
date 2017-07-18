NAME = lem-in
SRC = main.c get_next_line.c split.c algoritm_and_other.c input.c rooms.c malloc_and_free.c
SRCO = $(SRC:.c=.o)
INCLUDES = lem_in.h
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRCO)
	@make -C libft
	@make -C ft_printf
	@gcc $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(FT_PRINTF)
	@echo "\033[32;1m<lem-in>   | done"

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "\033[32;1m<lem-in>   | clean succes"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "\033[32;1m<lem-in>   | fclean succes"

re: fclean all
	@echo "\033[32;1m<lem-in>   | re succes"
