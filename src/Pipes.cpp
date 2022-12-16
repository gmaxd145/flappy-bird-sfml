#include "Pipes.hpp"
#include "Definitions.hpp"
#include <algorithm>
#include <ctime>

Pipes::Pipes(gameDataPtr gameData) : _gameData(gameData)
{
    _gameData->assetManager.loadTexture("Upper pipe", UPPER_PIPE_FILEPATH);
    _gameData->assetManager.loadTexture("Bottom pipe", BOTTOM_PIPE_FILEPATH);
    _gameData->assetManager.loadTexture("Scoring pipe", SCORING_PIPE_FILEPATH);

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

    sf::Sprite scoringPipe(_gameData->assetManager.getTexture("Scoring pipe"));
    scoringPipe.setPosition(_gameData->window.getSize().x + (upperPipeSprite.getGlobalBounds().width * 2),0);
    _scorPipesSprites.push_back(scoringPipe);
}
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
    for (auto scoringPipesScriptes = _scorPipesSprites.begin();
         scoringPipesScriptes != _scorPipesSprites.end();
         ++scoringPipesScriptes)
    {
        if ((*scoringPipesScriptes).getPosition().x + (*scoringPipesScriptes).getGlobalBounds().width < 0)
        {
            _scorPipesSprites.erase(_scorPipesSprites.begin(), scoringPipesScriptes);
        }
        else
        {
            (*scoringPipesScriptes).move(-movement, 0);
        }
    }
}

void Pipes::draw()
{
    for (auto& pipeSprite : _pipesSprites)
    {
        _gameData->window.draw(pipeSprite);
    }
    for (auto& scoringPipeSprite : _scorPipesSprites)
    {
        _gameData->window.draw(scoringPipeSprite);
    }
}

void Pipes::randPipeOffset()
{
    auto landHeight = _gameData->assetManager.getTexture("Land").getSize().y;
    _pipeSpawnYOffset = std::rand() % (landHeight + 1);
}

const std::vector<sf::Sprite>& Pipes::getSprites() const
{
    return _pipesSprites;
}

const std::vector<sf::Sprite>& Pipes::getScoreSprites() const
{
    return _scorPipesSprites;
}

void Pipes::deleteScorePipe(int index)
{
    _scorPipesSprites.erase(_scorPipesSprites.begin() + index);
}
