#pragma once

#include "../GameEngine/State.hpp"
#include "../GameEngine/Game.hpp"
#include <SFML/Graphics.hpp>

class MenuState : public State
{
public:
    MenuState(gameDataPtr gameData);

    void handleInput() final;
    void update(float dt) final;
    void draw(float dt) final;

private:
    gameDataPtr _gameData;

    sf::Sprite _backgroundSprite;
    sf::Sprite _titleSprite;
    sf::Sprite _playButtonSprite;
};