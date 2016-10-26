cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost COMPONENTS date_time REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

 
set(CMAKE_CXX_FLAGS "-msse2 -msse3 -O3 -std=c++11")


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/Data)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})



set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ALL_DYN_LINK ON)   # force dynamic linking for all libraries



set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath,. -L${CMAKE_CURRENT_BINARY_DIR}")

set(srcs View/simple.cpp
          Data/LogReader.cpp)

add_executable(LogViewer ${srcs})

target_link_libraries(LogViewer                      
                      ${Boost_LIBRARIES}
                      ${OpenCV_LIBS} 
                      boost_system
                      boost_filesystem
                      boost_thread)
