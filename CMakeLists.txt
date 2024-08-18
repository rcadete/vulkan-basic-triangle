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

find_package(GLEW CONFIG REQUIRED)

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

set(DEMO_04_SOURCES
        src/demo04/main.cpp)
add_executable(demo04 ${DEMO_04_SOURCES})
target_link_libraries(demo04 PRIVATE glfw GLEW::GLEW)

set(DEMO_05_SOURCES
        src/demo05/main.cpp)
add_executable(demo05 ${DEMO_05_SOURCES})
target_link_libraries(demo05 PRIVATE glfw GLEW::GLEW)

set(DEMO_06_SOURCES
        src/demo06/main.cpp)
add_executable(demo06 ${DEMO_06_SOURCES})
target_link_libraries(demo06 PRIVATE glfw glad::glad)

set(DEMO_07_SOURCES
        src/demo07/main.cpp)
add_executable(demo07 ${DEMO_07_SOURCES})
target_link_libraries(demo07 PRIVATE glfw glad::glad)

set(DEMO_08_SOURCES
        src/demo08/main.cpp)
add_executable(demo08 ${DEMO_08_SOURCES})
target_link_libraries(demo08 PRIVATE glfw glad::glad)

set(DEMO_09_SOURCES
        src/demo09/main.cpp)
add_executable(demo09 ${DEMO_09_SOURCES})
target_link_libraries(demo09 PRIVATE glfw glad::glad)

set(DEMO_10_SOURCES
        src/demo10/main.cpp)
add_executable(demo10 ${DEMO_10_SOURCES})
target_link_libraries(demo10 PRIVATE glfw glad::glad)

set(DEMO_11_SOURCES
        src/demo11/main.cpp
        src/demo11/Camera.cpp
        src/demo11/Line.cpp
        src/demo11/Line.h)
add_executable(demo11 ${DEMO_11_SOURCES})
target_link_libraries(demo11 PRIVATE glfw glad::glad glm::glm)
