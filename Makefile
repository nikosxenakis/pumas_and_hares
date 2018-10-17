#COMPILER OPTIONS
CXX := g++
CXXFLAGS := -g -std=gnu++11 -Wall 

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
	@echo "\tLinking..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

all: $(BIN) land
	@echo "\t$(BIN) ready."

test:
	make -C ./test run

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

.PHONY: test clean all land run run_land
