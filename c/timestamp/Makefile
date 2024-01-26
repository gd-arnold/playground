TARGET = main

CC = gcc
CFLAGS = -std=c17 -g -Wall

BUILD_DIR = build
SRC_DIR = src

CFILES = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJECTS = $(patsubst %.c, %.o, $(CFILES))

all: directories $(TARGET)

directories:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

run: all
	$(BUILD_DIR)/$(TARGET)

valgrind: all
	valgrind $(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/$(TARGET) $(OBJECTS)