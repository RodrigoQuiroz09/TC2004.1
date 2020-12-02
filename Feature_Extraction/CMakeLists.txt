# cmake needs this line
cmake_minimum_required(VERSION 3.13)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
include (/Users/chrisMac/Desktop/dlib-19.21/dlib/cmake)
if(NOT CMAKE_BUILD_TYPE AND NOT (MSVC_IDE OR XCODE))
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type, one of: Release, Debug" FORCE)
endif()

# Set target name, change with your favorite name
project(my_project)

message( STATUS "Build type: ${CMAKE_BUILD_TYPE}" )
message( STATUS "Configuration types: ${CMAKE_CONFIGURATION_TYPES}" )

# Detect 64 or 32 bit
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit project
    SET(64_BIT_OS TRUE)
    message( STATUS "A 64-bit OS detected" )
else()
    SET(64_BIT_OS FALSE)
    message( STATUS "A 32-bit OS detected" )
endif()

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI

    set(OpenCV_DIR "/Users/chrisMac/opencv/build/")
    #set(dlib_DIR "/usr/local/Cellar/dlib/19.21/include/dlib")



#find_package(OpenCV REQUIRED)
find_package(OpenCV REQUIRED PATHS /Users/chrisMac/opencv/build/)
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

#find_package(dlib REQUIRED)

file(GLOB srcs *.cpp *.c)
file(GLOB hdrs *.hpp *.h)

include_directories("${CMAKE_CURRENT_LIST_DIR}")

macro(add_example name)
    #add_executable(my_project source/featureExtraction_Dlib.cpp)
    #Use line below to try more examples when compiling
    add_executable(my_project source/moduleFE.cpp source/main.cpp)  
    #target_link_libraries(my_project PRIVATE ${OpenCV_LIBS}) 
    target_link_libraries(my_project dlib::dlib ${OpenCV_LIBS})
endmacro()

add_example(facemask)
