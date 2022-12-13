#include "GameState.hpp"
#include "../Definitions.hpp"
#include "../Pipes.hpp"

GameState::GameState(gameDataPtr gameData) : _gameData(gameData)
{
}

// maybe move init body to constructor and remove init
void GameState::init()
{
    // maybe rework assetManager
    _gameData->assetManager.loadTexture("Background", BACKGROUND_FILEPATH);

    _gameData->assetManager.loadTexture("Upper pipe", UPPER_PIPE_FILEPATH);
    _gameData->assetManager.loadTexture("Bottom pipe", BOTTOM_PIPE_FILEPATH);

    _pipesPtr = std::make_unique<Pipes>(_gameData);

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
        }
    }
}

void GameState::update(float dt)
{
    if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
    {
//        _pipesPtr->spawnInvisiblePipe();
        _pipesPtr->spawnBottomPipe();
        _pipesPtr->spawnUpperPipe();
        _clock.restart();
    }
    _pipesPtr->movePipes(dt);
}

void GameState::draw(float dt)
{
    _gameData->window.clear( sf::Color::Red );

    _gameData->window.draw(_backgroundSprite);

    _pipesPtr->drawPipes();

    _gameData->window.display();
}
