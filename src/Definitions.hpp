#pragma once

enum GameStates
{
    ready,
    playing,
    gameOver
};

enum BirdStates
{
    falling,
    flying
};

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define BACKGROUND_FILEPATH "data/resources/sky.png"

#define GAME_TITLE_FILEPATH "data/resources/title.png"
#define PLAY_BUTTON_FILEPATH "data/resources/PlayButton.png"

#define UPPER_PIPE_FILEPATH "data/resources/PipeDown.png"
#define BOTTOM_PIPE_FILEPATH "data/resources/PipeUp.png"
#define SCORING_PIPE_FILEPATH "data/resources/InvisibleScoringPipe.png"

#define PIPE_MOVEMENT_SPEED 350
#define PIPE_SPAWN_FREQUENCY 0.75

#define LAND_FILEPATH "data/resources/land.png"

#define BIRD_FRAME_1 "data/resources/bird-01.png"
#define BIRD_FRAME_2 "data/resources/bird-02.png"
#define BIRD_FRAME_3 "data/resources/bird-03.png"
#define BIRD_FRAME_4 "data/resources/bird-04.png"

#define BIRD_TIME_BETWEEN_FRAMES 0.1

#define GRAVITY 500

#define BIRD_FLYING_SPEED 400
#define BIRD_FLYING_DURATION 0.25
#define BIRD_ROTATION_SPEED 100

#define FLAPPY_FONT_FILEPATH "data/fonts/FlappyFont.ttf"

#define GAME_OVER_BODY_FILEPATH "data/resources/Game-Over-Body.png"
//#define GAME_OVER_BODY_FILEPATH "game_over_body_without_medal.png"
#define GAME_OVER_TITLE_FILEPATH "data/resources/Game-Over-Title.png"