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

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#find_package(SFML 2 REQUIRED COMPONENTS graphics window system)
find_package(SFML 2 REQUIRED COMPONENTS graphics window system)


add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
if (UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# Copy data dir to the binary directory
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#if(MSVC)
#    foreach(lib ${SFML_LIBS})
#        get_target_property(lib_path ${lib} LOCATION)
#        file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#    endforeach()
#endif(MSVC)





