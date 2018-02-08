# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:55 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/27 19:24:08 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -c

SRC = main.c read.c check_line.c check_line_add.c\
	  write_room.c init_room.c write_pipe.c bfs_alghoritm.c\
      search.c free_functions.c alg_each_nbr.c count_functions.c\
      print_rezult.c del_cross_rez.c add_func.c print_lines.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo lem-in object deleted

fclean: clean

re: fclean all


.PHONY: clean fclean all re
