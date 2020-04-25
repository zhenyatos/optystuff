cmake_minimum_required (VERSION 3.11)

project(optystuff
		VERSION 0.1
		DESCRIPTION "Writing numerical optimization methods stuff"
		LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# library code is here
add_subdirectory(src)

# executable code is here
add_subdirectory(app)
