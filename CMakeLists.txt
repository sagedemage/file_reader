cmake_minimum_required(VERSION 3.22 VERSION 0.1.0)

project(FileReader)

file(GLOB_RECURSE SOURCE_FILES "src/*.c" "src/*.h" "third_party_libs/*.c" "third_party_libs/*.h")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(STANDARD_C_VERSION_FLAG "-std=c17")
set(OPTIMIZE_FLAG "-O3")
set(WARNING_FLAGS "-Werror -Wpedantic -Wall -Wextra -Wno-unknown-pragmas -Wno-unused-parameter")
set(DEBUG_FLAGS "-g")

file(COPY text_files DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${STANDARD_C_VERSION_FLAG} ${OPTIMIZE_FLAG} ${WARNING_FLAGS} ${DEBUG_FLAGS}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#target_link_libraries(${PROJECT_NAME})

