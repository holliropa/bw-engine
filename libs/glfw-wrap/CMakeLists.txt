cmake_minimum_required(VERSION 3.14)
project(bw-glfw-wrap
        VERSION 0.3
        LANGUAGES CXX)

add_library(glfw-wrap INTERFACE)
add_library(bw::glfw-wrap ALIAS glfw-wrap)

target_include_directories(glfw-wrap INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(glfw-wrap INTERFACE cxx_std_20)