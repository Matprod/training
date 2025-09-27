CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = gol

all: $(TARGET)

$(TARGET): gol.c
	$(CC) $(CFLAGS) -o $(TARGET) utils.c gol.c

clean:
	rm -f $(TARGET)