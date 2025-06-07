cmake_minimum_required(VERSION 3.10)
project(DifferentialEquationSolver VERSION 2.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(solver ${SOURCES})

# Set output directory
set_target_properties(solver PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install target
install(TARGETS solver DESTINATION bin)