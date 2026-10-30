cmake_minimum_required(VERSION 3.10)
project(GROUP9_ML1)

cmake_minimum_required(VERSION 3.16)

project(Group9ML1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ml_project
    src/main.cpp
    src/ml_pipeline.cpp
)

add_library(closed_form src/closed_form.cpp)

add_executable(closed_form_example
    examples/closed_form_example.cpp
)
target_link_libraries(closed_form_example PRIVATE closed_form)

add_executable(test_closed_form
    tests/test_closed_form.cpp
)
target_link_libraries(test_closed_form PRIVATE closed_form)

enable_testing()
add_test(NAME ClosedFormTests COMMAND test_closed_form)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Tell the compiler where to find header files
include_directories(include)

# Stitch the source files together into an executable
add_executable(ml_project src/main.cpp src/ml_pipeline.cpp)