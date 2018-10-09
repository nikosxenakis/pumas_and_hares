#COMPILER OPTIONS
CFLAGS := -g -Wall

CC := g++ $(CFLAGS)

#DIRECTORIES
BASE_DIR := .

SRC_DIR := $(BASE_DIR)/src

HEADER_DIR := $(BASE_DIR)/include

BUILD_DIR := $(BASE_DIR)/build

BIN_DIR := $(BASE_DIR)/bin

TEST_DIR := $(BASE_DIR)/test

#FILES
BIN := $(BIN_DIR)/pumas_and_hares

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(BASE_DIR)/main.cpp

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $<

$(BIN): $(OBJ_FILES)
	@echo " Linking..."
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@

all: $(BIN)
	@echo " $(BIN) ready."

test:
	make -C ./test test

run: $(BIN)
	$(BIN)

clean: $(BIN)
	@echo " Cleaning..."
	rm -rf $(BIN_DIR) $(BUILD_DIR)

.PHONY: test clean
