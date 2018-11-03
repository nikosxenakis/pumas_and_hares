#COMPILER OPTIONS
CXX := g++
CXXFLAGS := -g -Wall -std=c++11 -O3

#DIRECTORIES
BASE_DIR := ..
BASE_TEST_DIR := .
SRC_DIR := $(BASE_DIR)/src
BUILD_DIR := $(BASE_DIR)/build
BIN_DIR := $(BASE_DIR)/bin
SRC_TEST_DIR := $(BASE_TEST_DIR)/src
BUILD_TEST_DIR := $(BASE_TEST_DIR)/build

#FILES
TEST_TARGET := test
TEST_BIN := $(BIN_DIR)/$(TEST_TARGET)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_TEST_FILES := $(wildcard $(SRC_TEST_DIR)/*.cpp) 
OBJ_TEST_FILES := $(patsubst $(SRC_TEST_DIR)/%.cpp, $(BUILD_TEST_DIR)/%.o, $(SRC_TEST_FILES))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

$(BUILD_TEST_DIR)/%.o: $(SRC_TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_TEST_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_BIN): $(OBJ_TEST_FILES) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_TEST_FILES) $(OBJ_FILES) -o $@

clean:
	@echo "Cleaning tests..."
	rm -r $(BUILD_TEST_DIR)/*

.PHONY: test clean
