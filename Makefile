CC = gcc
CFLAGS = -Werror -Wpedantic -Wall -Wextra -Wno-unused-parameter -g

# Local sources and objects
SOURCES = $(shell find src/ third_party_libs/ -type f -iname '*.c')
OBJECTS = $(foreach x, $(basename $(SOURCES)), $(x).o)

BIN_DIRECTORY = bin
TARGET = $(BIN_DIRECTORY)/file_reader

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIRECTORY)
	$(CC) $^ -o $@
