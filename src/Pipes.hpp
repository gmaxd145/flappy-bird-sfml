#pragma once

#include <vector>
#include "GameEngine/Game.hpp"
#include "SFML/Graphics.hpp"

class Pipes
{
public:
    Pipes(gameDataPtr gameData);

    void spawnUpperPipe();
    void spawnBottomPipe();
    // ?
//    void spawnInvisiblePipe();
    void movePipes(float dt);
    void drawPipes();

private:
    gameDataPtr _gameData;

    std::vector<sf::Sprite> _pipesSprites;
};