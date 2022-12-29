#include <fstream>
#include "GameState.hpp"
#include "../Definitions.hpp"
#include "GameOverState.hpp"
#include "filesystem"

bool checkSpritesCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
    sf::Rect<float> rect1(sprite1.getGlobalBounds());
    sf::Rect<float> rect2(sprite2.getGlobalBounds());

    return rect1.intersects(rect2);
}

//bool checkSpritesCollision(const sf::Sprite& sprite1, const std::vector<sf::Sprite>& sprites)
//{
//    for (const auto& sprite2: sprites)
//    {
//        return checkSpritesCollision(sprite1, sprite2);
//    }
//}

GameState::GameState(const gameDataPtr& gameData) : _gameData(gameData), _pipes(gameData), _land(gameData),
                                                    _bird(gameData), _hud(gameData)
{
    _gameData->assetManager.loadTexture("Background", BACKGROUND_FILEPATH);
    _backgroundSprite.setTexture(_gameData->assetManager.getTexture("Background"));

//    _gameData->assetManager.loadSound("Hit sound", HIT_SOUND_FILEPATH);
//    _gameData->assetManager.loadSound("Score sound", SCORE_SOUND_FILEPATH);
//    _gameData->assetManager.loadSound("Wing sound", WING_SOUND_FILEPATH);
//    _hitSound.setBuffer(_gameData->assetManager.getSound("Hit sound"));
//    _hitSound.setBuffer(_gameData->assetManager.getSound("Score sound"));
//    _hitSound.setBuffer(_gameData->assetManager.getSound("Wing sound"));
    _hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH);
    _scoreSoundBuffer.loadFromFile(SCORE_SOUND_FILEPATH);
    _wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH);
    _hitSound.setBuffer(_hitSoundBuffer);
    _scoreSound.setBuffer(_scoreSoundBuffer);
    _wingSound.setBuffer(_wingSoundBuffer);

    _gameState = GameStates::ready;
}

void GameState::handleInput()
{
    sf::Event event;
    while(_gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _gameData->window.close();
        }
        if (_gameData->inputManager.isSpriteClicked(_backgroundSprite, sf::Mouse::Left,
                                                    _gameData->window)
                                                    &&
                                                    _gameState != GameStates::gameOver)
        {
            _bird.tap();
            _gameState = GameStates::playing;
            _wingSound.play();
        }
    }
}

void GameState::update(float dt)
{
    if (_gameState == GameStates::playing)
    {
        _land.move(dt);
        _bird.animate();
        _pipes.move(dt);
        if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
        {
            _pipes.randPipeOffset();
            _pipes.spawn();
            _clock.restart();
        }
        _bird.update(dt);
    }

//    if (checkSpritesCollision(_bird.getSprite(), _land.getSprites())
//        ||
//        checkSpritesCollision(_bird.getSprite(), _pipes.getSprites()))
//    {
//        _gameState = GameStates::gameOver;
//    }
    auto landSprites(_land.getSprites());
    for (const auto& landSprite: landSprites)
    {
        if (checkSpritesCollision(_bird.getSprite(), landSprite))
        {
            _gameState = GameStates::gameOver;
            _hitSound.play();
        }
    }
    auto pipeSprites(_pipes.getSprites());
    for (const auto& pipeSprite: pipeSprites)
    {
        if (checkSpritesCollision(_bird.getSprite(), pipeSprite))
        {
            _gameState = GameStates::gameOver;
            _hitSound.play();
        }
    }

//    for (auto scorePipeSpriteIt = _pipes._scorPipesSprites.begin();
//         scorePipeSpriteIt != _pipes._scorPipesSprites.end();
//        ++scorePipeSpriteIt)
//    {
//        if (checkSpritesCollision(_bird.getSprite(), (*scorePipeSpriteIt)))
//        {
//            _pipes._scorPipesSprites.erase(scorePipeSpriteIt);
//            _hud.updateScore(++_score);
//        }
//    }

    const auto& scorPipesSprites = _pipes.getScoreSprites();
    for (auto scorePipeSpriteIt = scorPipesSprites.begin();
         scorePipeSpriteIt != scorPipesSprites.end();
         ++scorePipeSpriteIt)
    {
        if (checkSpritesCollision(_bird.getSprite(), (*scorePipeSpriteIt)))
        {
            _pipes.deleteScorePipe(scorePipeSpriteIt - scorPipesSprites.begin());
            _hud.updateScore(++_score);
            _scoreSound.play();
        }
    }



    if (_gameState == GameStates::gameOver)
    {
        std::string filepath = std::filesystem::current_path().string();
        filepath.erase(filepath.find("cmake-build-debug"), filepath.size());
        std::fstream file(filepath + "data/Highscore.txt");
        if (!file.is_open())
        {
            throw std::runtime_error("Can not open highscore file.");
        }
        int temp{};
        file >> temp;
        if (_score > temp)
        {
            file.seekg(std::ios::beg);
            file << _score;
        };

        _gameData->stateMachine.addState(statePtr(new GameOverState(_gameData, _score)),
                                         true);
    }
}

void GameState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_backgroundSprite);
    _pipes.draw();
    _land.draw();
    _bird.draw();
    _hud.draw();

    _gameData->window.display();
}
