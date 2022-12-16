#include "GameOverState.hpp"
#include "../Definitions.hpp"
#include "GameState.hpp"
#include <fstream>
#include <filesystem>

GameOverState::GameOverState(gameDataPtr gameData, int score) : _gameData(gameData), _score(score)
{
    _gameData->assetManager.loadTexture("Game over body", GAME_OVER_BODY_FILEPATH);
    _gameData->assetManager.loadTexture("Game over title", GAME_OVER_TITLE_FILEPATH);

    _background.setTexture(_gameData->assetManager.getTexture("Background"));
    _gameOverTitle.setTexture(_gameData->assetManager.getTexture("Game over title"));
    _gameOverBody.setTexture(_gameData->assetManager.getTexture("Game over body"));
    _retryButton.setTexture(_gameData->assetManager.getTexture("Play button"));

    _gameOverBody.setPosition((_gameData->window.getSize().x / 2) - (_gameOverBody.getGlobalBounds().width / 2),
                              (_gameData->window.getSize().y / 2) - (_gameOverBody.getGlobalBounds().height / 2));
    _gameOverTitle.setPosition((_gameData->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
                                _gameOverBody.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2));
    _retryButton.setPosition((_gameData->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2),
                             _gameOverBody.getPosition().y + _gameOverBody.getGlobalBounds().height +
                                (_retryButton.getGlobalBounds().height * 0.2));

    _scoreText.setFont(_gameData->assetManager.getFont("Flappy font"));
    _scoreText.setString(std::to_string(_score));
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setCharacterSize(50);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _scoreText.setPosition(_gameOverBody.getPosition().x + (_gameOverBody.getGlobalBounds().width * 4 / 5),
                           _gameData->window.getSize().y / 2.15);

    std::string filepath = std::filesystem::current_path().string();
    filepath.erase(filepath.find("cmake-build-debug"), filepath.size());
    std::ifstream file(filepath + "data/Highscore.txt");
    if (!file.is_open())
    {
        throw std::runtime_error("Can not open highscore file.");
    }
    file >> _highscore;

    _highscoreText.setFont(_gameData->assetManager.getFont("Flappy font"));
    _highscoreText.setString(std::to_string(_highscore));
    _highscoreText.setFillColor(sf::Color::White);
    _highscoreText.setCharacterSize(50);
    _highscoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _highscoreText.setPosition(_gameOverBody.getPosition().x + (_gameOverBody.getGlobalBounds().width * 4 / 5),
                               _gameData->window.getSize().y / 1.8);


}

void GameOverState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_background);
    _gameData->window.draw(_gameOverBody);
    _gameData->window.draw(_gameOverTitle);
    _gameData->window.draw(_retryButton);
    _gameData->window.draw(_scoreText);
    _gameData->window.draw(_highscoreText);

    _gameData->window.display();
}

void GameOverState::handleInput()
{
    sf::Event event;
    while (_gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _gameData->window.close();
        }

        if (_gameData->inputManager.isSpriteClicked(_retryButton, sf::Mouse::Left, _gameData->window))
        {
            _gameData->stateMachine.addState(statePtr (new GameState(_gameData)), true);
        }
    }
}

void GameOverState::update(float dt)
{
}