cmake_minimum_required( VERSION 3.7.0)
project("RageJava")

include (GenerateExportHeader)

include_directories(C:/Program Files/Java/jdk1.8.0_131)

find_package(JNI REQUIRED)
if (JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
else ()
    message(ERROR "JNI not found!")
endif ()

#file(GLOB_RECURSE  SOURCES src/*.cpp)
#file(GLOB_RECURSE  HEADERS src/*.hpp)
#
#include_directories(include)
#
#add_library(RageJava SHARED ${SOURCES} ${HEADERS})


set(_src_root_path "${RageJava_SOURCE_DIR}/src")
file(
        GLOB_RECURSE _source_list
        LIST_DIRECTORIES false
        "${_src_root_path}/*.c*"
        "${_src_root_path}/*.h*"
)

add_library(RageJava SHARED ${_source_list})

foreach(_source IN ITEMS ${_source_list})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()