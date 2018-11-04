#ifndef STR
#define XSTR(x) #x
#define STR(x) XSTR(x)
#endif

#ifndef RESOURCES_PATH
#define RESOURCES_PATH ./resources
#define INPUT_FILES_PATH ./resources/input_files
#define CONFIG_PATH ./resources/configurations
#endif

#ifndef TEST_DECLARATIONS
#define TEST_DECLARATIONS

#define LIB_PATH ../lib
#define HEADERS_PATH ../../include/

#include STR(LIB_PATH/catch.hpp)

#endif