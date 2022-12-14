#include "GameState.hpp"
#include "../Definitions.hpp"

GameState::GameState(const gameDataPtr& gameData) : _gameData(gameData), _pipes(gameData), _land(gameData)
{
    _gameData->assetManager.loadTexture("Background", BACKGROUND_FILEPATH);

    _backgroundSprite.setTexture(_gameData->assetManager.getTexture("Background"));
}

void GameState::handleInput()
{
    sf::Event event;

    while(_gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _gameData->window.close();
        }
        if (_gameData->inputManager.isSpriteClicked(_backgroundSprite, sf::Mouse::Left,
                                                    _gameData->window))
        {
            // bird jump
        }
    }
}

void GameState::update(float dt)
{
    if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
    {
        _pipes.randPipeOffset();
        _pipes.spawn();
        _clock.restart();
    }
    _pipes.move(dt);

    _land.move(dt);
}

void GameState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_backgroundSprite);
    _pipes.draw();
    _land.draw();

    _gameData->window.display();
}
