CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = polyset

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp array_bag.cpp searchable_array_bag.cpp searchable_tree_bag.cpp set.cpp tree_bag.cpp

clean:
	rm -f $(TARGET)