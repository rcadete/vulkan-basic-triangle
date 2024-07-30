cmake_minimum_required(VERSION 3.28)
project(vulkan-basic-triangle)

set(CMAKE_CXX_STANDARD 23)

find_package(glad CONFIG REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

find_package(Vulkan REQUIRED)
message(STATUS "Found Vulkan: ${Vulkan_LIBRARIES}")
message(STATUS "Vulkan include dirs: ${Vulkan_INCLUDE_DIRS}")

find_package(OpenGL REQUIRED)
message(STATUS "Found OpenGL: ${OPENGL_LIBRARIES}")

find_package(glm CONFIG REQUIRED)


#print all include dirs for this project
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
message(STATUS "include dir='${dir}'")
endforeach()


set(DEMO_01_SOURCES
        src/demo01/main.cpp)
add_executable(demo01 ${DEMO_01_SOURCES})
target_link_libraries(demo01)

set(DEMO_02_SOURCES
        src/demo02/main.cpp)
add_executable(demo02 ${DEMO_02_SOURCES})
target_link_libraries(demo02 PRIVATE glfw Vulkan::Vulkan)

set(DEMO_03_SOURCES
        src/demo03/main.cpp)
add_executable(demo03 ${DEMO_03_SOURCES})
target_link_libraries(demo03 PRIVATE glfw glad::glad glm::glm)
