#pragma once

#include "GameEngine/Game.hpp"

class Land
{
public:
    Land(gameDataPtr gameData);

    void move(float dt);

    void draw();

    const std::vector<sf::Sprite>& getSprites() const;

private:
    gameDataPtr _gameData;

    std::vector<sf::Sprite> _landSprites;
};