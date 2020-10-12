# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile (3)                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoppe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:20:53 by jhoppe            #+#    #+#              #
#    Updated: 2019/03/04 16:03:14 by jbashiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LNAME = libft
SRCS = *.c
LINCLUDES = libft
LIB = fillit.h
INCLUDE = fillit.h libft/libft.a
OBJ = $(SRCS:.c=.o)
NORMA = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft fclean && make -C libft
		gcc $(NORMA) -c $(SRCS)
		gcc -o $(NAME) -I $(INCLUDE) $(OBJ)

.c.o:
		gcc $(NORMA) -I $(LIB) -g -c -o $(NAME) $<

clean:
		@rm -f $(OBJ)
		@rm -f libft/$(OBJ)
		@rm -f libft/libft.h.gch

fclean: clean
		@rm -f $(NAME)
		@rm -f libft/libft.a

re: fclean all

.PHONY: clean fclean all re
