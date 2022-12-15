#pragma once
#include "GameEngine/Game.hpp"

class HUD
{
public:
    HUD(gameDataPtr gameData);

    void updateScore(int score);
    void draw();

private:
    gameDataPtr _gameData;

    sf::Text _scoreText;
};