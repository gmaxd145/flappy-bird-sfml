#include "AssetManager.hpp"

void AssetManager::loadTexture(const std::string &name, const std::string &fileName)
{
    sf::Texture texture;
    if(texture.loadFromFile(fileName))
    {
//        _textures.insert({name, t})
        _textures[name] = texture;
    }
}

// Do i need a reference?
sf::Texture& AssetManager::getTexture(const std::string &name)
{
    return _textures.at(name);
}

void AssetManager::loadFont(const std::string &name, const std::string &fileName)
{
    sf::Font font ;
    if(font.loadFromFile(fileName))
    {
//        _fonts.insert({name, t})
        _fonts[name] = font;
    }
}

// Do i need a reference?
sf::Font& AssetManager::getFont(const std::string &name)
{
    return _fonts.at(name);
}

