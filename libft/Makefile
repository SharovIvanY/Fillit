# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:34:14 by jbashiri          #+#    #+#              #
#    Updated: 2018/12/08 17:59:33 by jbashiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
HEAD = -c libft.h 
SRCS = *.c
OBJ = *.o

all: $(NAME) 

$(NAME):
	gcc $(FLAG) $(HEAD) $(SRCS)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
