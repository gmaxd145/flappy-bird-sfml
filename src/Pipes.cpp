#include "Pipes.hpp"
#include "Definitions.hpp"
#include <algorithm>
#include <ctime>


//don’t need to call function SpawnInvisiblePipe(), just solve issue in function MovePipes, use 2 loops instead of 1,
// first loop for move, second loop for erase the pipe which is out of width of window.
// Don’t just use 1 loop for erase and move, that leads to problem

Pipes::Pipes(gameDataPtr gameData) : _gameData(gameData),
                                     _landHeight(_gameData->assetManager.getTexture("Land").getSize().y)
{
    _gameData->assetManager.loadTexture("Upper pipe", UPPER_PIPE_FILEPATH);
    _gameData->assetManager.loadTexture("Bottom pipe", BOTTOM_PIPE_FILEPATH);

    srand(time(NULL));
}

void Pipes::spawn()
{
    sf::Sprite upperPipeSprite(_gameData->assetManager.getTexture("Upper pipe"));
    upperPipeSprite.setPosition(_gameData->window.getSize().x, 0 - _pipeSpawnYOffset);
    _pipesSprites.push_back(upperPipeSprite);

    sf::Sprite bottomPipeSprite(_gameData->assetManager.getTexture("Bottom pipe"));
    bottomPipeSprite.setPosition(_gameData->window.getSize().x,
                                _gameData->window.getSize().y - bottomPipeSprite.getGlobalBounds().height - _pipeSpawnYOffset);
    _pipesSprites.push_back(bottomPipeSprite);
}

//void Pipes::spawnInvisiblePipe()
//{
//    sf::Sprite sprite(_gameData->assetManager.getTexture("Upper pipe"));
//    sprite.setPosition(_gameData->window.getSize().x,
//                       _gameData->window.getSize().y - sprite.getGlobalBounds().height);
//    sprite.setColor(sf::Color(0, 0, 0, 0));
//    _pipesSprites.push_back(sprite);
//}

void Pipes::move(float dt)
{
    float movement = PIPE_MOVEMENT_SPEED * dt;
    for (auto pipesSpritesIt = _pipesSprites.begin();
        pipesSpritesIt != _pipesSprites.end();
        ++pipesSpritesIt)
    {
        if ((*pipesSpritesIt).getPosition().x + (*pipesSpritesIt).getGlobalBounds().width < 0)
        {
            _pipesSprites.erase(_pipesSprites.begin(), pipesSpritesIt);
        }
        else
        {
            (*pipesSpritesIt).move(-movement, 0);
        }
    }
}

void Pipes::draw()
{
    for (auto& pipeSprite : _pipesSprites)
    {
        _gameData->window.draw(pipeSprite);
    }
}

void Pipes::randPipeOffset()
{
    _pipeSpawnYOffset = std::rand() % (_landHeight + 1);
}