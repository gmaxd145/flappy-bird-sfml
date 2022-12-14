#pragma once

#include <vector>
#include "GameEngine/Game.hpp"
#include "SFML/Graphics.hpp"

class Pipes
{
public:
    Pipes(gameDataPtr gameData);

    void spawn();
//    void spawnInvisiblePipe();
    void move(float dt);
    void draw();
    void randPipeOffset();

private:
    gameDataPtr _gameData;

    std::vector<sf::Sprite> _pipesSprites;

    int _landHeight;
    int _pipeSpawnYOffset;
};