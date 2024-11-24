# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 10:37:51 by fclaus-g          #+#    #+#              #
#    Updated: 2024/11/17 12:35:22 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

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
