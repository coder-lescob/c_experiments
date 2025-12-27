SRC     := src
BUILD   := .gitignore/build
OBJ_DIR := $(BUILD)/obj
BIN_DIR := $(BUILD)/bin

CC := gcc
OBJFLAGS := -c -g -Wall -Wextra -O0 -I$(SRC)
CFLAGS   := -Wall -Wextra -O0 -g

SRC_C := $(wildcard $(SRC)/*.c)
SRC_S := $(wildcard $(SRC)/*.s)
OBJ_C := $(patsubst $(SRC)/%.c,$(OBJ_DIR)/%.o,$(SRC_C))
OBJ_S := $(patsubst $(SRC)/%.s,$(OBJ_DIR)/%.o,$(SRC_S))
ALLOBJ:= $(OBJ_C) $(OBJ_S)

.PHONY: all
all: clean build run

.PHONY: clean
clean:
	@clear
	@echo "CLEANING DONE"
	@rm -rf $(BUILD)/*

.PHONY: build
build: $(ALLOBJ)
	@echo "LINKING DONE"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(ALLOBJ) -o $(BIN_DIR)/main

# compile C sources to object files
$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "COMPILING $< DONE"
	@$(CC) $(OBJFLAGS) -c $< -o $@

# compile assembly sources to object files
$(OBJ_DIR)/%.o: $(SRC)/%.s
	@mkdir -p $(OBJ_DIR)
	@echo "ASSEMBLING $< DONE"
	@$(CC) $(OBJFLAGS) -c $< -o $@

.PHONY: run
run:
	@clear
	@echo "RUNNING PROGRAM MAIN:"
	@$(BIN_DIR)/main