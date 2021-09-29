# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 13:57:15 by jaekjung          #+#    #+#              #
#    Updated: 2021/09/30 04:19:20 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = ./sources/
INC = ./includes/
OBJ = ./objects/

SRCFILES = $(SRC)main.c $(SRC)logic.c $(SRC)utils.c $(SRC)parser.c $(SRC)string_utils.c $(SRC)error.c $(SRC)guard.c $(SRC)ft_split.c $(SRC)mapcheck.c
OBJFILES = $(addprefix $(OBJ), $(notdir $(SRCFILES:.c=.o)))

all : $(NAME)

$(OBJ)%.o: $(SRC)%.c
	gcc -c $(FLAGS) -o $@ $^ -I $(INC)

$(NAME): $(OBJFILES)
	gcc $(FLAGS) -o $(NAME) $(OBJFILES)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re