#COMPILER OPTIONS
CXX := g++
CXXFLAGS := -g -Wall -std=c++11

#DIRECTORIES
BASE_DIR := .

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

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(BASE_DIR)/main.cpp

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN): $(OBJ_FILES)
	@echo " Linking..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

all: $(BIN) land
	@echo " $(BIN) ready."

test:
	make -C ./test test

land: $(LAND_DIR)/$(LAND_TARGET).cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(LAND_GEN_BIN) $(LAND_DIR)/$(LAND_TARGET).cpp

run: $(BIN)
	$(BIN)

run_land: $(LAND_GEN_BIN)
	$(LAND_GEN_BIN)

clean:
	@echo " Cleaning..."
	rm -r $(BIN_DIR)/*
	rm -r $(BUILD_DIR)/*

.PHONY: test clean
