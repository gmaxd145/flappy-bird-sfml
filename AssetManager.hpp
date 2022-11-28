//TODO: UnloadTexture method: to unload the texture when we move to a new state or we don't require it

#pragma once

#include <SFML/Graphics.hpp>

#include <map>

class AssetManager
{
public:
    void loadTexture(const std::string& name, const std::string& fileName);
    sf::Texture& getTexture(const std::string& name);

    void loadFont(const std::string& name, const std::string& fileName);
    sf::Font& getFont(const std::string& name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};
