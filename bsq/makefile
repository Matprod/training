CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bsq

all: $(TARGET)

$(TARGET): bsq.c
	$(CC) $(CFLAGS) -o $(TARGET) utils.c bsq.c main.c map.c

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re