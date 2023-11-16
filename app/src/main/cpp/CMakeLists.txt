cmake_minimum_required(VERSION 3.18.1)
project("androidsdlthread")

#SDL统一路径
set(sdl_path ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
#添加SDL头文件
include_directories(${CMAKE_SOURCE_DIR}/include/SDL)
#添加SDL库
add_library(sdl SHARED IMPORTED)
set_target_properties(sdl PROPERTIES IMPORTED_LOCATION ${sdl_path}/libSDL2.so)

add_library(sdl_shared SHARED IMPORTED)
set_target_properties(sdl_shared PROPERTIES IMPORTED_LOCATION ${sdl_path}/libc++_shared.so)

add_library(sdl_main SHARED IMPORTED)
set_target_properties(sdl_main PROPERTIES IMPORTED_LOCATION ${sdl_path}/libmain.so)

add_library(
        androidsdlthread
        SHARED
        native-lib.cpp
        ${CMAKE_SOURCE_DIR}/logger.h)
find_library(
        log-lib
        log)
target_link_libraries( # Specifies the target library.
        androidsdlthread
        sdl
        sdl_shared
        sdl_main
        -landroid
        ${log-lib})