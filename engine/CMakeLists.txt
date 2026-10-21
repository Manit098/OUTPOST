
cmake_minimum_required(VERSION 3.20)

project(OUTPOST
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# The independent simulation engine
add_library(outpost_engine
    src/simulation.cpp
)

target_include_directories(outpost_engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# HTTP API server
find_package(Crow CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(outpost_server
    src/api/main.cpp
)

target_link_libraries(outpost_server
    PRIVATE
        outpost_engine
        Crow::Crow
        nlohmann_json::nlohmann_json
)

# Helpful compiler warnings
target_compile_options(outpost_engine PRIVATE
    -Wall -Wextra -Wpedantic
)

target_compile_options(outpost_server PRIVATE
    -Wall -Wextra -Wpedantic
)
