#ifndef STR
#define XSTR(x) #x
#define STR(x) XSTR(x)
#endif

#ifndef RESOURCES_PATH
#define RESOURCES_PATH ./resources
#endif

#ifndef TEST_DECLARATIONS
#define TEST_DECLARATIONS

#define LIB_PATH ../lib
#define HEADERS_PATH ../../include/

#include STR(LIB_PATH/catch.hpp)

#endif