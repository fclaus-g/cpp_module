NAME = ScalarConverter

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re