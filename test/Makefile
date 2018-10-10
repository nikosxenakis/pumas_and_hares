CC := g++ 

CFLAGS := -g -Wall -Wextra -Werror -std=gnu++11

HEADER_FILES := $(wildcard ../include/*.hpp)
SRC_FILES := $(wildcard ../src/*.cpp)


test: tests.cpp ../src/landscape.cpp
	$(CC) $(CFLAGS) $(HEADER_FILES) $(SRC_FILES) tests.cpp -o test
	./test
