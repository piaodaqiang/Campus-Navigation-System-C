CC = gcc
CFLAGS = -Iinclude -Wall -O2

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)
