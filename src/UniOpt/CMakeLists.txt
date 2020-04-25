set(HEADER_LIST 
"include/opty/UniOpt.h"
"include/opty/FibUniOpt.h"
"include/opty/DihUniOpt.h")

add_library(UniOpt
UniOpt.cpp
FibUniOpt.cpp
DihUniOpt.cpp)

target_include_directories(UniOpt PUBLIC include)