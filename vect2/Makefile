CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
NAME = vec


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) vect22.cpp main.cpp

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

