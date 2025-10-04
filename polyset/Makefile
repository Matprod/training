CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
NAME = polyset


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) array_bag.cpp searchable_array_bag.cpp searchable_tree_bag.cpp tree_bag.cpp set.cpp main.cpp

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

