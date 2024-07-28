cmake_minimum_required(VERSION 3.28)
project(vulkan-basic-triangle C)

set(CMAKE_C_STANDARD 23)

add_executable(vulkan-basic-triangle src/main.c)
target_link_libraries(vulkan-basic-triangle glfw vulkan)