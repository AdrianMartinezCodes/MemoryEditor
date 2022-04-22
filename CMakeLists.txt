cmake_minimum_required(VERSION 3.10)
project(MemoryEditor VERSION 0.1)

file(GLOB SOURCES src/*.cpp)

configure_file(MemoryEditorConfig.h.in MemoryEditorConfig.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(MemoryFunctions)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(MemoryEditor PUBLIC MemoryFunctions)

target_include_directories(MemoryEditor PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MemoryFunctions"
                           )

install(TARGETS MemoryEditor DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/MemoryEditorConfig.h"
    DESTINATION include
    )
