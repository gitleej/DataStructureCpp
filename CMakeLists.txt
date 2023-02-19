cmake_minimum_required(VERSION 3.21)
project(DataStructureCpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/Utilities/include/)
aux_source_directory(${CMAKE_SOURCE_DIR}/Utilities/src/ UTILITIES_SRC_LIST)

add_subdirectory(./List)
add_subdirectory(./Tree)
add_subdirectory(./BinarySearchTree)
add_subdirectory(./Array)
add_subdirectory(./String)
add_subdirectory(./Stack)
add_subdirectory(./Recursion)
add_subdirectory(./Other)

add_executable(DataStructureCpp main.cpp ${UTILITIES_SRC_LIST})
