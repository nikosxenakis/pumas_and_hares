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

#FILES
TARGET := test

BIN := $(BIN_DIR)/$(TARGET)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) 

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


test: $(TEST_FILES) $(OBJ_FILES) test_main.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) test_main.o $(TEST_DIR)/test_landscape.cpp $(TEST_DIR)/test_tile.cpp $(TEST_DIR)/test_hare.cpp -o $(BIN_DIR)/test

test_main.o: test_main.cpp
	g++ -std=c++11 test_main.cpp -c

run test: $(TARGET)
	$(TARGET)