set(HEADER_LIST 
"include/opty/Newton.h")

add_library(Newton
Newton.cpp)

target_link_libraries(Newton PRIVATE Numerical)

target_include_directories(Newton PUBLIC include)