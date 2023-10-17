# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siran <siran@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 22:36:52 by siran             #+#    #+#              #
#    Updated: 2023/10/15 22:46:52 by siran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = rush-02

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c \
	  useful_functions.c \
	  atoi.c \
	  check.c \
	  dictionary.c \
	  printing.c \
	  read_files.c \
	  str-check.c \
	  
OBJECTS = $(SOURCES: .c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

