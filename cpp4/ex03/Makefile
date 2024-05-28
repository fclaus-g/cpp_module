# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 13:11:27 by fclaus-g          #+#    #+#              #
#    Updated: 2024/05/28 12:06:01 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	AMateria.cpp \
	Character.cpp \
	MateriaSource.cpp \
	Ice.cpp \
	Cure.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -g $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
