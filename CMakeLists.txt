cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

include_directories(
UniOpt 
Numerical 
GradOpt 
GradOpt/FastGradStep 
GradOpt/AdaptGradStep 
Newton)

add_executable (optystuff "main.cpp" 
"UniOpt/UniOpt.h" "UniOpt/UniOpt.cpp"
"UniOpt/Dih/DihUniOpt.h" "UniOpt/Dih/DihUniOpt.cpp"
"UniOpt/Fib/FibUniOpt.h" "UniOpt/Fib/FibUniOpt.cpp"
"Numerical/derivative.h" "Numerical/derivative.cpp"
"Numerical/vec.h" "Numerical/vec.cpp"
"Numerical/mat.h" "Numerical/mat.cpp"
"Numerical/linalg.h" "Numerical/linalg.cpp"
"GradOpt/GradOpt.h" "GradOpt/GradOpt.cpp"
"GradOpt/FastGradStep/FastGradStep.h" "GradOpt/FastGradStep/FastGradStep.cpp"
"GradOpt/AdaptGradStep/AdaptGradStep.h" "GradOpt/AdaptGradStep/AdaptGradStep.cpp"
"Newton/Newton.h" "Newton/Newton.cpp")
