set(HEADER_LIST 
"include/opty/AdaptGradStep.h"
"include/opty/FastGradStep.h"
"include/opty/GradOpt.h")

add_library(GradOpt
AdaptGradStep.cpp
FastGradStep.cpp
GradOpt.cpp)

target_link_libraries(GradOpt PRIVATE Numerical UniOpt)

target_include_directories(GradOpt PUBLIC include)