#include "Land.hpp"
#include "Definitions.hpp"

Land::Land(gameDataPtr gameData) : _gameData(gameData)
{
    _gameData->assetManager.loadTexture("Land", LAND_FILEPATH);

    sf::Sprite landSprite1, landSprite2;
    landSprite1.setTexture(_gameData->assetManager.getTexture("Land"));
    landSprite2.setTexture(_gameData->assetManager.getTexture("Land"));

    landSprite1.setPosition(0,_gameData->window.getSize().y - (landSprite1.getGlobalBounds().height));
    landSprite2.setPosition(_gameData->window.getSize().x,
                            _gameData->window.getSize().y - (landSprite1.getGlobalBounds().height));

    _landSprites.push_back(std::move(landSprite1));
    _landSprites.push_back(std::move(landSprite2));
}

void Land::move(float dt)
{
    float landMovementSpeed = PIPE_MOVEMENT_SPEED;
    float movement = landMovementSpeed * dt;
    for (auto landSpritesIt = _landSprites.begin();
         landSpritesIt != _landSprites.end();
         ++landSpritesIt)
    {
        (*landSpritesIt).move(-movement, 0);

        if ((*landSpritesIt).getPosition().x < 0 - (*landSpritesIt).getGlobalBounds().width)
        {
            (*landSpritesIt).setPosition(_gameData->window.getSize().x - 10,
                                         (*landSpritesIt).getPosition().y);
        }
    }
}

void Land::draw()
{
    for (const auto& landSprite : _landSprites)
    {
        _gameData->window.draw(landSprite);
    }
}

const std::vector<sf::Sprite>& Land::getSprites() const
{
    return _landSprites;
}