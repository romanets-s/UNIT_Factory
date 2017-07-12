#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprosian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 15:16:40 by sprosian          #+#    #+#              #
#    Updated: 2017/01/25 18:28:52 by sromanet         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = buf.c check.c create_list.c del_list.c ft_bzero.c ft_putstr.c ft_strlen.c\
	list_size.c main.c read.c square.c square_two.c struct_data.c validation.c
SRCO = $(SRC:.c=.o)
INCLUDES = fillit.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO)
	gcc $(FLAGS) -o $(NAME) $(SRCO)

.c.o:
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
