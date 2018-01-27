# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:39 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/27 19:39:37 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
OBJ =  objects/*.o
LIBNAME = objects/libftlemin.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): objectdir
	@make -C libft
	@make -C src
	@ar rc $(LIBNAME) $(OBJ)
	@gcc $(FLAGS) $(LIBNAME) -o $(NAME) 
	@echo "\033[35m --------- ants ready to go ------------\033[0m"

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C src
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m --------------lem-in deleted--------------\033[0m"

re: fclean all

.PHONY: clean all fclean re
