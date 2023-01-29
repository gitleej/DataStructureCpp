cmake_minimum_required(VERSION 3.22)
project(DataStructureCpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/Utilities/include/)
aux_source_directory(${CMAKE_SOURCE_DIR}/Utilities/src/ UTILITIES_SRC_LIST)

add_executable(DataStructureCpp main.cpp ${UTILITIES_SRC_LIST})
