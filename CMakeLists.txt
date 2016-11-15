cmake_minimum_required(VERSION 3.2)
project(P4 CXX)

ADD_SUBDIRECTORY(lib)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

ADD_EXECUTABLE(color2grayscale color2grayscale.cpp)
TARGET_LINK_LIBRARIES(color2grayscale image)
set_property(TARGET color2grayscale PROPERTY CXX_STANDARD 11)

enable_testing()
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/deps/cxxtest)

find_package(CxxTest REQUIRED)
include_directories(${CXXTEST_INCLUDE_DIR})

CXXTEST_ADD_TEST(test_heap_priority_queue test_heap_priority_queue.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/test_heap_priority_queue.h abstract_list.h dynamic_array_list.h dynamic_array_list.txx abstract_priority_queue.h heap_priority_queue.h heap_priority_queue.txx)
set_property(TARGET test_heap_priority_queue PROPERTY CXX_STANDARD 11)

add_executable(propagate propagate.cpp abstract_list.h dynamic_array_list.h dynamic_array_list.txx abstract_priority_queue.h heap_priority_queue.h heap_priority_queue.txx)
TARGET_LINK_LIBRARIES(propagate image)
set_property(TARGET propagate PROPERTY CXX_STANDARD 11)

add_test(propagate1 propagate ${CMAKE_SOURCE_DIR}/initial.png ${CMAKE_SOURCE_DIR}/speed.png final1.png 1)
add_test(propagate10 propagate ${CMAKE_SOURCE_DIR}/initial.png ${CMAKE_SOURCE_DIR}/speed.png final10.png 10)
add_test(propagate30 propagate ${CMAKE_SOURCE_DIR}/initial.png ${CMAKE_SOURCE_DIR}/speed.png final30.png 30)

