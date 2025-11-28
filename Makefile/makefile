CC = gcc
CFLAGS = -Iinclude -Wall
SRCS = src/main.c src/graph.c src/map.c src/navigation.c src/utils.c
OBJS = $(SRCS:.c=.o)
TARGET = navigation

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
