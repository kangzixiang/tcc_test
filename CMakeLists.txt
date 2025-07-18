cmake_minimum_required(VERSION 3.10...3.25 FATAL_ERROR)
project(tcc_test)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/products/bin)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -O0 -Wall -g2 -ggdb")
set(CMAKE_BUILD_TYPE Debug)

set(USER_HOME $ENV{HOME})
message(STATUS "User Home Directory: ${USER_HOME}")

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${USER_HOME}/tcc-host/include
)

link_directories(${USER_HOME}/tcc-host/lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TCC_TEST_SRC)
add_executable (${PROJECT_NAME} ${TCC_TEST_SRC})
target_link_libraries(${PROJECT_NAME} tcc)