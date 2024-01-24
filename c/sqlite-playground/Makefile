TARGET=main

CC=gcc
CFLAGS=-std=c17 -g -Wall -Werror
LDFLAGS=-Llib
LDLIBS=-lsqlite3

CFILES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c, %.o, $(CFILES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I./include -c -o $@ $^

run: all
	@LD_LIBRARY_PATH=lib ./$(TARGET)

clean:
	rm -rf $(TARGET) $(OBJECTS)
