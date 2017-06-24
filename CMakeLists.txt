cmake_minimum_required( VERSION 3.7.0)
project("RageJava")

include (GenerateExportHeader)

find_package(JNI REQUIRED)
if (JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
else ()
    message(ERROR "JNI not found!")
endif ()

file(GLOB_RECURSE  SOURCES src/*.cpp)
file(GLOB_RECURSE  HEADERS src/*.hpp)

include_directories(include)

add_library(RageJava SHARED ${SOURCES} ${HEADERS})
