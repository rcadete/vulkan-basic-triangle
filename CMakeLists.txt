cmake_minimum_required(VERSION 3.28)
project(vulkan-basic-triangle)

set(CMAKE_CXX_STANDARD 23)

set(GLFW_ROOT E:/Workspace/MyPrograms/glfw-3.4.bin.WIN64)
include_directories(${GLFW_ROOT}/include)
link_directories(${GLFW_ROOT}/lib-mingw-w64)

#set(VULKAN_ROOT E:/Workspace/MyPrograms/vulkan)
#include_directories(${VULKAN_ROOT}/Include)
#link_directories(${VULKAN_ROOT}/Lib)

find_package(Vulkan REQUIRED)
message(STATUS "Found Vulkan: ${Vulkan_LIBRARIES}")
message(STATUS "Vulkan include dirs: ${Vulkan_INCLUDE_DIRS}")

find_package(OpenGL REQUIRED)
message(STATUS "Found OpenGL: ${OPENGL_LIBRARIES}")


set(SHADER_SOURCES
        src/main.cpp)
add_executable(vulkan-basic-triangle ${SHADER_SOURCES})

target_link_libraries(vulkan-basic-triangle glfw3 Vulkan::Vulkan ${OPENGL_LIBRARIES})