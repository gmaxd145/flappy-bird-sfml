#pragma once

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include <SFML/Graphics.hpp>

struct GameData
{
    StateMachine stateMachine;
    sf::RenderWindow window;
    AssetManager assetManager;
    InputManager inputManager;
};

typedef std::shared_ptr<GameData> gameDataPtr;

class Game
{
public:
    Game(int width, int height, const std::string& title);

private:
    void Run();

    float _dt = 1.0f / 60.0f;
    sf::Clock _clock;
    gameDataPtr _gameData = std::make_shared<GameData>();
};