# Makefile for Example Project

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
EXAMPLES_DIR = examples
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Executable file
EXECUTABLE = example_app

# Default target
all: $(EXECUTABLE)

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to compile the source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Variable to control the compilation of a specific example
EXAMPLE_NAME ?= main.c

# Rule to build a specific example binary
example: $(BUILD_DIR) $(BUILD_DIR)/$(EXAMPLE_NAME:.c=)

$(BUILD_DIR)/$(EXAMPLE_NAME:.c=): $(EXAMPLES_DIR)/$(EXAMPLE_NAME) $(OBJECTS)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $@

# Clean the generated files
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

# Run the example binary
run: $(BUILD_DIR)/$(EXAMPLE_NAME:.c=)
	./$(BUILD_DIR)/$(EXAMPLE_NAME:.c=)

