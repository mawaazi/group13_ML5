
cmake_minimum_required(VERSION 3.16)

project(Group9ML1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

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

