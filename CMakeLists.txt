cmake_minimum_required(VERSION 3.26.0)
project(VulkanTest VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRCS src/*.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD_EXTENSIONS 20)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()

include_directories(src)

add_executable(${PROJECT_NAME} ${SRCS})

message(STATUS "Using find_package to locate Vulkan")
find_package(Vulkan REQUIRED)
message(STATUS "Vulkan Found = ${Vulkan_FOUND}")
message(STATUS "Vulkan Include = ${Vulkan_INCLUDE_DIR}")
message(STATUS "Vulkan Lib = ${Vulkan_LIBRARY}")

message(STATUS "Using find_package to locate GLFW3")
find_package(glfw3 REQUIRED)
message(STATUS "GLFW3 Found = ${glfw3_FOUND}")

message(STATUS "Using find_package to locate GLM")
find_package(glm REQUIRED)
message(STATUS "GLM Found = ${glm_FOUND}")

find_package(X11 REQUIRED)
#include_directories(${X11_INCLUDEDIR})
#link_directories(${X11_LIBRARYDIR})

#find_package(pthread REQUIRED)
#find_package(Xxf86vm REQUIRED)
#find_package(Xrandr REQUIRED)
#find_package(Xi REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC ${Vulkan_LIBRARIES} glfw glm::glm X11 dl pthread)