cmake_minimum_required(VERSION 3.31)
project("bw_engine" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)

add_subdirectory(extern/glad)
add_subdirectory(extern/glfw)
add_subdirectory(extern/glm)

add_subdirectory(libs/glad-wrap)
add_subdirectory(libs/glfw-wrap)

set(LIBRARY_NAME engine)
set(LIBRARY_ALIAS bw::engine)

add_library(${LIBRARY_NAME}
        src/application.cpp
        src/engine.cpp
        src/game.cpp
        src/input.cpp
)
add_library(${LIBRARY_ALIAS} ALIAS ${LIBRARY_NAME})

target_include_directories(${LIBRARY_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>   # Public headers
        $<INSTALL_INTERFACE:include>                            # Installed location
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/glm>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw>
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>      # Explicitly require internal prefix
)

target_link_libraries(${LIBRARY_NAME}
        PUBLIC
        glm
        glad
        glfw
        bw::glad-wrap
        bw::glfw-wrap
)

#enable_testing()
#add_subdirectory(tests)
