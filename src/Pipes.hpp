#pragma once

#include "GameEngine/Game.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

class Pipes
{
public:
    Pipes(gameDataPtr gameData);

    void spawn();
    void move(float dt);
    void draw();
    void randPipeOffset();

    const std::vector<sf::Sprite>& getSprites() const;

    const std::vector<sf::Sprite>& getScoreSprites() const;
    void deleteScorePipe(int index);

private:
    gameDataPtr _gameData;

    std::vector<sf::Sprite> _pipesSprites;

    std::vector<sf::Sprite> _scorPipesSprites;

    int _pipeSpawnYOffset;
};