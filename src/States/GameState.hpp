#pragma once

#include "../GameEngine/State.hpp"
#include "../GameEngine/Game.hpp"
#include "../Pipes.hpp"
#include <SFML/Graphics.hpp>

class GameState : public State
{
public:
    GameState(gameDataPtr gameData);

    void init() final;

    void handleInput() final;
    void update(float dt) final;
    void draw(float dt) final;

private:
    gameDataPtr _gameData;

    sf::Sprite _backgroundSprite;

    std::unique_ptr<Pipes> _pipesPtr;
    sf::Clock _clock;
};