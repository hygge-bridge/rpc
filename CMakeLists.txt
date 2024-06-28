cmake_minimum_required(VERSION 3.0)
PROJECT(mprpc)

set(EXECUTABLE_OUTPUT_path ${PROJECT_SOURCE_DIRE}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
link_libraries(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(example)
add_subdirectory(src)