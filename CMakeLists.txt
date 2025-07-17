cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(tcc_test)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/products/bin)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -O0 -Wall -g2 -ggdb")

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/tinycc/include/
)
link_directories(${PROJECT_SOURCE_DIR}/tinycc/lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TCC_TEST_SRC)
add_executable (${PROJECT_NAME} ${TCC_TEST_SRC})
target_link_libraries(${PROJECT_NAME} tcc)