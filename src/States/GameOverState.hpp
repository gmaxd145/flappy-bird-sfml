#pragma once

#include "../GameEngine/State.hpp"
#include "../GameEngine/Game.hpp"
#include <SFML/Graphics.hpp>

class GameOverState : public State
{
public:
    GameOverState(gameDataPtr gameData, int score);

    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    gameDataPtr _gameData;

    sf::Sprite _background;

    sf::Sprite _gameOverTitle;
    sf::Sprite _gameOverBody;
    sf::Sprite _retryButton;

    sf::Text _scoreText;
    sf::Text _highscoreText;

    int _score{};
    int _highscore{};
};