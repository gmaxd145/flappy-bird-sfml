//TODO: UnloadTexture method: to unload the texture when we move to a new state ili we don't require it

#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
public:
    void loadTexture(const std::string& name, const std::string& fileName);
    sf::Texture& getTexture(const std::string& name);

    void loadFont(const std::string& name, const std::string& fileName);
    sf::Font& getFont(const std::string& name);

    void loadSound(const std::string& name, const std::string& fileName);
    sf::SoundBuffer& getSound(const std::string& name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
    std::map<std::string, sf::SoundBuffer> _sounds;
};
