cmake_minimum_required(VERSION 3.23)
set(PROJECT_NAME Flappy_Bird)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

file(GLOB source_files
        "src/*.cpp"
        "src/GameEngine/*.cpp"
        "src/States/*.cpp"
        )

set(SOURCES ${source_files})

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)


add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})




