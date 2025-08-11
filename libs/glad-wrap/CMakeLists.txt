cmake_minimum_required(VERSION 3.14)
project(bw-glad-wrap
        VERSION 0.3
        LANGUAGES CXX)

add_library(glad-wrap INTERFACE)
add_library(bw::glad-wrap ALIAS glad-wrap)

target_include_directories(glad-wrap INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(glad-wrap INTERFACE cxx_std_20)