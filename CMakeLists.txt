cmake_minimum_required(VERSION 3.0.2)
project(gamejam)

if (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB gs_src ${SRC_DIR}/*.*)

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.1 COMPONENTS graphics window system audio REQUIRED)

#find_package(Boost 1.55 COMPONENTS system filesystem REQUIRED)
#message(STATUS "Boost found: ${Boost_FOUND}, ${Boost_VERSION}")

#find_package(Bullet 2.82 REQUIRED)
#find_package(GLUT 2.8 REQUIRED)
#find_package(GLEW 1.10 REQUIRED)
#find_package(GLM 0.9.5 REQUIRED)

add_executable(gamejam ${gs_src})
target_include_directories(gamejam PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(gamejam PUBLIC ${SFML_LIBRARIES})