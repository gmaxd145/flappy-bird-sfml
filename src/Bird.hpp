#pragma once

#include "GameEngine/Game.hpp"
#include "SFML/Graphics.hpp"

class Bird
{
public:
    Bird(gameDataPtr gameData);

    void draw();

    void animate();

    void update(float dt);

    void tap();

    const sf::Sprite& getSprite() const;

private:
    gameDataPtr _gameData;

    sf::Sprite _birdSprite;

    std::vector<sf::Texture> _animationFrames;
    int _animationIt{};
    sf::Clock _animationClock;

    int _birdState{};
    sf::Clock _moveClock;
    int _rotation{};
};