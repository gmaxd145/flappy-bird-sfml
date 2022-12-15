#include "GameState.hpp"
#include "../Definitions.hpp"

bool checkSpritesCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
    sf::Rect<float> rect1(sprite1.getGlobalBounds());
    sf::Rect<float> rect2(sprite2.getGlobalBounds());

    if (rect1.intersects(rect2))
    {
        return true;
    }
    return false;
}

//bool checkSpritesCollision(const sf::Sprite& sprite1, const std::vector<sf::Sprite>& sprites)
//{
//    for (const auto& sprite2: sprites)
//    {
//        return checkSpritesCollision(sprite1, sprite2);
//    }
//
//}

GameState::GameState(const gameDataPtr& gameData) : _gameData(gameData), _pipes(gameData), _land(gameData),
                                                    _bird(gameData), _hud(gameData)
{
    _gameData->assetManager.loadTexture("Background", BACKGROUND_FILEPATH);
    _backgroundSprite.setTexture(_gameData->assetManager.getTexture("Background"));

    _gameState = GameStates::ready;
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
                                                    _gameData->window)
                                                    &&
                                                    _gameState != GameStates::gameOver)
        {
            _bird.tap();
            _gameState = GameStates::playing;
        }
    }
}

void GameState::update(float dt)
{
    if (_gameState == GameStates::playing)
    {
        _land.move(dt);
        _bird.animate();
        _pipes.move(dt);
        if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
        {
            _pipes.randPipeOffset();
            _pipes.spawn();
            _clock.restart();
        }
        _bird.update(dt);
    }

    //    if (checkSpritesCollision(_bird.getSprite(), _land.getSprites())
//        ||
//        checkSpritesCollision(_bird.getSprite(), _pipes.getSprites()))
//    {
//        _gameState = GameStates::gameOver;
//    }
    auto landSprites(_land.getSprites());
    for (const auto& landSprite: landSprites)
    {
        if (checkSpritesCollision(_bird.getSprite(), landSprite))
        {
            _gameState = GameStates::gameOver;
        }
    }
    auto pipeSprites(_pipes.getSprites());
    for (const auto& pipeSprite: pipeSprites)
    {
        if (checkSpritesCollision(_bird.getSprite(), pipeSprite))
        {
            _gameState = GameStates::gameOver;
        }
    }

    for (auto scorePipeSpriteIt = _pipes._scorPipesSprites.begin();
         scorePipeSpriteIt != _pipes._scorPipesSprites.end();
        ++scorePipeSpriteIt)
    {
        if (checkSpritesCollision(_bird.getSprite(), (*scorePipeSpriteIt)))
        {
            _pipes._scorPipesSprites.erase(scorePipeSpriteIt);
            _hud.updateScore(++_score);
        }
    }

    if (_gameState == GameStates::gameOver)
    {
        // ?
        _gameData->stateMachine.addState(statePtr(new GameOverState(_gamedata)), true);
    }
}

void GameState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_backgroundSprite);
    _pipes.draw();
    _land.draw();
    _bird.draw();
    _hud.draw();

    _gameData->window.display();
}
