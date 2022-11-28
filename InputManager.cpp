#include "InputManager.hpp"

bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect spriteRect(sprite.getPosition().x, sprite.getPosition().y,
                              sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        if (spriteRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}