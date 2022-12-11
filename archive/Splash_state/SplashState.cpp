#include "SplashState.hpp"
#include "../Menu_state/MenuState.hpp"
#include "../../src/Definitions.hpp"
#include <iostream>

SplashState::SplashState(gameDataPtr gameData) : _gameData(gameData)
{
}

// maybe rework this
void SplashState::init()
{
    // maybe rework assetManager
    _gameData->assetManager.loadTexture("Splash state background", SPLASH_SCENE_BACKGROUND_FILEPATH);
    _backgroundSprite.setTexture(_gameData->assetManager.getTexture("Splash state background"));
}

void SplashState::handleInput()
{
    sf::Event event;

    while(_gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _gameData->window.close();
        }
    }
}

void SplashState::update(float dt)
{
    if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
         _gameData->stateMachine.addState(statePtr(new MenuState(_gameData)), true);
    }
}

void SplashState::draw(float dt)
{
    _gameData->window.clear();
    _gameData->window.draw(_backgroundSprite);
    _gameData->window.display();
}
