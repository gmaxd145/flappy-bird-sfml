#pragma once

#include "../GameEngine/State.hpp"
#include "../GameEngine/Game.hpp"
#include "../Pipes.hpp"
#include "../Land.hpp"
#include "../Bird.hpp"
#include "../HUD.hpp"
#include <SFML/Graphics.hpp>

class GameState : public State
{
public:
    GameState(const gameDataPtr& gameData);

    void handleInput() final;
    void update(float dt) final;
    void draw(float dt) final;



private:
    gameDataPtr _gameData;
    int _gameState;

    int _score{};
    int _highscore{};
    sf::Text _scoreText;
    sf::Text _highscoreText;
    HUD _hud;

    sf::Sprite _backgroundSprite;

    Land _land;

    Pipes _pipes;
    sf::Clock _clock;

    Bird _bird;
};