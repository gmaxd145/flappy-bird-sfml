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
    sf::Text _scoreText;
    sf::Text _highscoreText;
    HUD _hud;

    sf::Sprite _backgroundSprite;

    Land _land;

    Pipes _pipes;
    sf::Clock _clock;

    Bird _bird;

    sf::SoundBuffer _hitSoundBuffer;
    sf::SoundBuffer _scoreSoundBuffer;
    sf::SoundBuffer _wingSoundBuffer;
    sf::Sound _hitSound;
    sf::Sound _scoreSound;
    sf::Sound _wingSound;
};