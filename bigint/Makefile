CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = big


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) bigint2.cpp main.cpp

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

