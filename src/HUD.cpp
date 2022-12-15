#include "HUD.hpp"
#include "Definitions.hpp"

HUD::HUD(gameDataPtr gameData) : _gameData(gameData)
{
    _gameData->assetManager.loadFont("Flappy font", FLAPPY_FONT_FILEPATH);
    _scoreText.setFont(_gameData->assetManager.getFont("Flappy font"));
    _scoreText.setString("0");
    _scoreText.setCharacterSize(100);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _scoreText.setPosition(_gameData->window.getSize().x / 2, _gameData->window.getSize().y * 0.1);
}

void HUD::draw()
{
    _gameData->window.draw(_scoreText);
}

void HUD::updateScore(int score)
{
    _scoreText.setString(std::to_string(score));
}

