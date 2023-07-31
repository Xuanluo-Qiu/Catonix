# Makefile for Example Project

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -I$(INCLUDE_DIR)

# Directories
SRC_DIR = src
INCLUDE_DIR = include
EXAMPLES_DIR = examples
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Executable file
EXECUTABLE = $(BIN_DIR)/example_app

# Default target
all: $(EXECUTABLE)

# Rule to create the build and bin directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Rule to compile the source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
$(EXECUTABLE): $(BIN_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Variable to control the compilation of a specific example
EXAMPLE_NAME ?= main.c

# Rule to build a specific example binary
example: $(BIN_DIR) $(BIN_DIR)/$(EXAMPLE_NAME:.c=)

$(BIN_DIR)/$(EXAMPLE_NAME:.c=): $(EXAMPLES_DIR)/$(EXAMPLE_NAME) $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $@

# Clean the generated files
clean:
	rm -rf $(BUILD_DIR)

# Run the example binary
run: $(BIN_DIR)/$(EXAMPLE_NAME:.c=)
	./$(BIN_DIR)/$(EXAMPLE_NAME:.c=)
