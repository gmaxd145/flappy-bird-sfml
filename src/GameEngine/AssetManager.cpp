#include "AssetManager.hpp"

void AssetManager::loadTexture(const std::string &name, const std::string &fileName)
{
    sf::Texture texture;
    if(texture.loadFromFile(fileName))
    {
        _textures[name] = texture;
    }
}

sf::Texture& AssetManager::getTexture(const std::string &name)
{
    return _textures.at(name);
}

void AssetManager::loadFont(const std::string &name, const std::string &fileName)
{
    sf::Font font ;
    if(font.loadFromFile(fileName))
    {
        _fonts[name] = font;
    }
}

sf::Font& AssetManager::getFont(const std::string &name)
{
    return _fonts.at(name);
}


void AssetManager::loadSound(const std::string &name, const std::string &fileName)
{
    sf::SoundBuffer soundBuffer;
    if(soundBuffer.loadFromFile(fileName))
    {
        _sounds[name] = soundBuffer;
    }
}

sf::SoundBuffer& AssetManager::getSound(const std::string &name)
{
    return _sounds.at(name);
}
