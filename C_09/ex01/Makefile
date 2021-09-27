# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 15:19:38 by jaekjung          #+#    #+#              #
#    Updated: 2021/09/27 15:20:44 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -c

SRC = ./sources/
INC = ./includes/
OBJ = ./objects/

TARGET = libft.a
SRCFILES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJFILES = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all