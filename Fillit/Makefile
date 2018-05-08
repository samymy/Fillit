# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 10:55:46 by vpaladii          #+#    #+#              #
#    Updated: 2017/10/28 19:57:39 by vpaladii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = main.c read_input.c node_matrix.c node_elem.c linking_ops.c \
additional.c free_mem_ops.c field_ops.c solve_alg.c tetra_arr_ops.c \
gather_elems.c valid.c others.c additional2.c fuck_moulinette.c \
fuck_moulinette2.c

CFLAGS = -Wall -Wextra -Werror
OBJ = $(notdir $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
