# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 12:49:29 by fclaus-g          #+#    #+#              #
#    Updated: 2024/04/23 16:41:46 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp contact.cpp phonebook.cpp 

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
