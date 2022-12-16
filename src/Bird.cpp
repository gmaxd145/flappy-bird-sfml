#include "Bird.hpp"
#include "Definitions.hpp"

#include <iostream>

Bird::Bird(gameDataPtr gameData) : _gameData(gameData)
{
    _gameData->assetManager.loadTexture("Bird frame 1", BIRD_FRAME_1);
    _gameData->assetManager.loadTexture("Bird frame 2", BIRD_FRAME_2);
    _gameData->assetManager.loadTexture("Bird frame 3", BIRD_FRAME_3);
    _gameData->assetManager.loadTexture("Bird frame 4", BIRD_FRAME_4);

    _animationFrames = {
            _gameData->assetManager.getTexture("Bird frame 1"),
             _gameData->assetManager.getTexture("Bird frame 2"),
            _gameData->assetManager.getTexture("Bird frame 3"),
            _gameData->assetManager.getTexture("Bird frame 4")
    };

    _birdSprite.setTexture(_animationFrames[_animationIt]);

    _birdSprite.setPosition(_gameData->window.getSize().x / 2 - _birdSprite.getGlobalBounds().width,
                            _gameData->window.getSize().y * 0.25);

//    _birdState = BIRD_STATE_STILL;
    _birdSprite.setOrigin(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);

}

void Bird::draw()
{
    _gameData->window.draw(_birdSprite);
}

void Bird::animate()
{
    if (_animationClock.getElapsedTime().asSeconds() > BIRD_TIME_BETWEEN_FRAMES)
    {
        ++_animationIt;
        _animationIt %= 4;

        _birdSprite.setTexture(_animationFrames[_animationIt]);
        _animationClock.restart();
    }
}

void Bird::update(float dt)
{
    if (_birdSprite.getPosition().y < 0 + _birdSprite.getGlobalBounds().height)
    {
        _birdState = BirdStates::falling;
    }
    switch (_birdState)
    {
        case BirdStates::falling:
            _birdSprite.move(0, GRAVITY * dt);

            _rotation += BIRD_ROTATION_SPEED * dt;

            if (_rotation > 50)
            {
                _rotation = 50;
            }
            _birdSprite.setRotation(_rotation);
            break;
        case BirdStates::flying:
            _birdSprite.move(0, -BIRD_FLYING_SPEED * dt);

            _rotation -= BIRD_ROTATION_SPEED * dt;

            if (_rotation < -25)
            {
                _rotation = -25;
            }
            _birdSprite.setRotation(_rotation);
            break;
    }
    if (_moveClock.getElapsedTime().asSeconds() > BIRD_FLYING_DURATION)
    {
        _birdState = BirdStates::falling;
        _moveClock.restart();
    }
}

void Bird::tap()
{
    _birdState = BirdStates::flying;
    _moveClock.restart();
}

const sf::Sprite& Bird::getSprite() const
{
    return _birdSprite;
}