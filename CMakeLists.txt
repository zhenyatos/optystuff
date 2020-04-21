cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

include_directories(UniOpt Numerical GradOpt)

add_executable (optystuff "main.cpp" 
"UniOpt/UniOpt.h" "UniOpt/UniOpt.cpp"
"UniOpt/Dih/DihUniOpt.h" "UniOpt/Dih/DihUniOpt.cpp"
"UniOpt/Fib/FibUniOpt.h" "UniOpt/Fib/FibUniOpt.cpp"
"Numerical/derivative.h" "Numerical/derivative.cpp"
"Numerical/vecfun.h" "Numerical/vecfun.cpp"
"GradOpt/GradOpt.h" "GradOpt/GradOpt.cpp")
