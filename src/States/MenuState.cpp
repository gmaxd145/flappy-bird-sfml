#include "MenuState.hpp"
#include "../Definitions.hpp"

MenuState::MenuState(gameDataPtr gameData) : _gameData(gameData)
{
}

// maybe move init body to draw and remove init
void MenuState::init()
{
    // maybe rework assetManager
    _gameData->assetManager.loadTexture("Main menu background", MAIN_MENU_BACKGROUND_FILEPATH);
    _gameData->assetManager.loadTexture("Game title",GAME_TITLE_FILEPATH);
    _gameData->assetManager.loadTexture("Play button", PLAY_BUTTON_FILEPATH);

    _backgroundSprite.setTexture(_gameData->assetManager.getTexture("Main menu background"));
    _titleSprite.setTexture(_gameData->assetManager.getTexture("Game title"));
    _playButtonSprite.setTexture(_gameData->assetManager.getTexture("Play button"));
}

void MenuState::handleInput()
{
    sf::Event event;

    while(_gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _gameData->window.close();
        }

        if (_gameData->inputManager.isSpriteClicked(_playButtonSprite, sf::Mouse::Left,
                                                    _gameData->window))
        {
            // Go to game screen
        }
    }
}

void MenuState::update(float dt)
{
}

void MenuState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_backgroundSprite);
    _gameData->window.draw(_titleSprite);
    _gameData->window.draw(_playButtonSprite);

    _titleSprite.setPosition((SCREEN_WIDTH / 2) - (_titleSprite.getGlobalBounds().width / 2),
                             _titleSprite.getGlobalBounds().height / 2);
    _playButtonSprite.setPosition((SCREEN_WIDTH / 2) - (_playButtonSprite.getGlobalBounds().width / 2),
                                  (SCREEN_HEIGHT / 2) - (_playButtonSprite.getGlobalBounds().height / 2));

    _gameData->window.display();
}
