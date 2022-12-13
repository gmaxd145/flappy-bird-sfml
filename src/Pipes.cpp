#include "Pipes.hpp"
#include "Definitions.hpp"
#include <algorithm>

//don’t need to call function SpawnInvisiblePipe(), just solve issue in function MovePipes, use 2 loops instead of 1,
// first loop for move, second loop for erase the pipe which is out of width of window.
// Don’t just use 1 loop for erase and move, that leads to problem

// unite pipe spawn

Pipes::Pipes(gameDataPtr gameData) : _gameData(gameData)
{

}

void Pipes::spawnUpperPipe()
{
    sf::Sprite sprite(_gameData->assetManager.getTexture("Upper pipe"));
    sprite.setPosition(_gameData->window.getSize().x, 0);
    _pipesSprites.push_back(sprite);
}

void Pipes::spawnBottomPipe()
{
    sf::Sprite sprite(_gameData->assetManager.getTexture("Bottom pipe"));
    sprite.setPosition(_gameData->window.getSize().x,
                       _gameData->window.getSize().y - sprite.getGlobalBounds().height);
    _pipesSprites.push_back(sprite);
}

//void Pipes::spawnInvisiblePipe()
//{
//    sf::Sprite sprite(_gameData->assetManager.getTexture("Upper pipe"));
//    sprite.setPosition(_gameData->window.getSize().x,
//                       _gameData->window.getSize().y - sprite.getGlobalBounds().height);
//    sprite.setColor(sf::Color(0, 0, 0, 0));
//    _pipesSprites.push_back(sprite);
//}

void Pipes::movePipes(float dt)
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

void Pipes::drawPipes()
{
    for (auto& pipeSprite : _pipesSprites)
    {
        _gameData->window.draw(pipeSprite);
    }
}
