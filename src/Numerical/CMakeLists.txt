set(HEADER_LIST 
"include/opty/derivative.h"
"include/opty/error.h"
"include/opty/linalg.h"
"include/opty/mat.h"
"include/opty/vec.h")

add_library(Numerical
derivative.cpp
linalg.cpp
mat.cpp
vec.cpp)

target_include_directories(Numerical PUBLIC include)