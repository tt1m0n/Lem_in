# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 18:09:32 by omakovsk          #+#    #+#              #
#    Updated: 2017/12/29 23:54:03 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra -c

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c\
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c\
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
	  ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c\
	  ft_lstnew.c ft_lstmap.c ft_mycount_words.c ft_myrev.c ft_myintiter.c\
	  ft_myfactor.c ft_mypower.c ft_get_next_line.c

OBJ	= $(SRC:.c=.o)

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo compilation done =\)

%.o: %.c
	@gcc $(FLAGS) $<

clean:
	@rm -f $(OBJ)
	@echo object files deleted -_-

fclean: clean
	@rm -f $(NAME)
	@echo libft.a deleted -_-

re: fclean all


.PHONY: clean fclean all re
