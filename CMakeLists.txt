cmake_minimum_required(VERSION 3.10)
project(tanksgame)

# use cmake/FindSDL2*.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# enable C++11
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -ggdb ${CMAKE_CXX_FLAGS}")


find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_mixer REQUIRED)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")
add_executable(tanksgame ${SOURCES})

# use cmake/FindSDL2*.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")


include_directories(
        "include/*"
        "include/"
        ${SDL2_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_NET_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
)

target_link_libraries(tanksgame
        ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_NET_LIBRARY}
        ${SDL2_MIXER_LIBRARY}
        )