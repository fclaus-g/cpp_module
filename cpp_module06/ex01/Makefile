# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:44:39 by fclaus-g          #+#    #+#              #
#    Updated: 2024/11/11 09:44:42 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

SRCS = main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created.$(RESET)"
%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "$(RED)$(NAME) object files removed.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)$(NAME) removed.$(RESET)"
re: fclean all

.PHONY: all clean fclean re