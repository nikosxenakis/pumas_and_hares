#COMPILER OPTIONS
CXX := g++
CXXFLAGS := -std=c++11 -Wall -O3

#DIRECTORIES
BASE_DIR := .
SRC_DIR := $(BASE_DIR)/src
HEADER_DIR := $(BASE_DIR)/include
BUILD_DIR := $(BASE_DIR)/build
BIN_DIR := $(BASE_DIR)/bin
TEST_DIR := $(BASE_DIR)/test
OUTPUT_DIR := $(BASE_DIR)/output
LAND_DIR := $(BASE_DIR)/land_generator
RESOURCES_DIR := $(BASE_DIR)/resources

#FILES
TARGET := pumas_and_hares
LAND_TARGET := land_generator
LAND_ENCHANCER := land_enchancer
TEST_TARGET := test

BIN := $(BIN_DIR)/$(TARGET)
LAND_GEN_BIN := $(BIN_DIR)/$(LAND_TARGET)
LAND_ENCHANCER_BIN := $(BIN_DIR)/$(LAND_ENCHANCER)
TEST_BIN := $(BIN_DIR)/$(TEST_TARGET)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(BASE_DIR)/main.cpp

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp) 

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(@eval $(RUN_ARGS):;@:)
endif

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.hpp 
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -pg -c -o $@ $<

$(BIN): $(OBJ_FILES)
	@echo "Linking..."
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

all: $(BIN) $(LAND_GEN_BIN) $(LAND_ENCHANCER_BIN) $(TEST_BIN)
	@echo "executables are ready"

$(TEST_BIN): $(BIN)
	make -C $(TEST_DIR) .$(TEST_BIN)

$(LAND_GEN_BIN): $(LAND_DIR)/$(LAND_TARGET).cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(LAND_GEN_BIN) $(LAND_DIR)/$(LAND_TARGET).cpp

$(LAND_ENCHANCER_BIN): $(LAND_DIR)/$(LAND_ENCHANCER).cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(LAND_ENCHANCER_BIN) $(LAND_DIR)/$(LAND_ENCHANCER).cpp

run: $(BIN)
	@mkdir -p $(OUTPUT_DIR)
	@rm -rf $(OUTPUT_DIR)/*
	@$(BIN) $(RUN_ARGS)
	@python ./scripts/data_analyzer.py

run_land_gen: $(LAND_GEN_BIN)
	@$(LAND_GEN_BIN)

run_land_enc: $(LAND_ENCHANCER_BIN)
	@$(LAND_ENCHANCER_BIN)

run_test: $(TEST_BIN)
	@$(TEST_BIN)

clean:
	@echo "Cleaning..."
	rm -r $(BIN_DIR)/*
	rm -r $(BUILD_DIR)/*
	make -C $(TEST_DIR) clean

.PHONY: all run run_land_gen run_land_enc run_test clean
