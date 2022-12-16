#include "Game.hpp"
#include "../States/MenuState.hpp"

Game::Game(int width, int height, const std::string &title)
{
    _gameData->window.create(sf::VideoMode(width, height), title,
                         sf::Style::Close | sf::Style::Titlebar);
    _gameData->stateMachine.addState(statePtr(new MenuState(_gameData)));

    Run();
}

void Game::Run()
{
    float newTime, frameTime;
    float currentTime = _clock.getElapsedTime().asSeconds();
    float accumulator = 0;

    while (_gameData->window.isOpen())
    {
        _gameData->stateMachine.processStateChanges();

        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;
        while(accumulator >= _dt)
        {
            _gameData->stateMachine.getActiveState()->handleInput();
            _gameData->stateMachine.getActiveState()->update(_dt);
            accumulator -= _dt;
        }
        _gameData->stateMachine.getActiveState()->draw(_dt);
    }
}