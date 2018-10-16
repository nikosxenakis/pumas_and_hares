#COMPILER OPTIONS
CXX := g++
CXXFLAGS := -g -Wall -std=c++11

#DIRECTORIES
BASE_DIR := ..

SRC_DIR := $(BASE_DIR)/src

HEADER_DIR := $(BASE_DIR)/include

BUILD_DIR := $(BASE_DIR)/build

BIN_DIR := $(BASE_DIR)/bin

TEST_DIR := $(BASE_DIR)/test

LAND_DIR := $(BASE_DIR)/land_generator

#FILES
TARGET := pumas_and_hares

LAND_TARGET := land_generator

BIN := $(BIN_DIR)/$(TARGET)

LAND_GEN_BIN := $(BIN_DIR)/$(LAND_TARGET)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) 

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: test
	./test

test: $(TEST_FILES) $(OBJ_FILES) test_main.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) test_main.o test_landscape.cpp test_tile.cpp test_hare.cpp -o $@

test_main.o: test_main.cpp
	g++ -std=c++11 test_main.cpp -c

