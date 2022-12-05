cmake_minimum_required(VERSION 3.23)
project(flappy_bird)

set(CMAKE_CXX_STANDARD 17)

add_executable(flappy_bird main.cpp
        game_engine/Game.cpp game_engine/Game.hpp
        game_engine/StateMachine.cpp game_engine/StateMachine.hpp
        game_engine/AssetManager.cpp game_engine/AssetManager.hpp
        game_engine/InputManager.cpp game_engine/InputManager.hpp
        States/Menu_state/MenuState.hpp
        States/Menu_state/MenuState.cpp)

#g++ main.cpp -o sfml-app game_engine/Game.cpp game_engine/Game.hpp game_engine/StateMachine.cpp game_engine/StateMachine.hpp game_engine/AssetManager.cpp game_engine/AssetManager.hpp game_engine/InputManager.cpp game_engine/InputManager.hpp States/Menu_state/MenuState.hpp States/Menu_state/MenuState.cpp -lsfml-graphics -lsfml-window -lsfml-system



