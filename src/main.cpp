#include "WindowSDL.h"
#include "WindowRayLib.h"
#include "GameManager.h"

int main(int argc, char** args)
{
    std::srand(std::time(nullptr));
    Window* win = nullptr;

    if (argc > 1) 
    {
        std::string arg = args[1];

        if (arg == "--raylib") win = new WindowRayLib();    // Utilisation de Raylib
        else if (arg == "--sdl") win = new WindowSDL();     // Utilisation de SDL
    }
    else 
    {
        //win = new WindowSDL();
        win = new WindowRayLib();
    }

    GameManager* gm = new GameManager();

    if (win->InitLib()) return 1;
    if (win->CreateWindow()) return 1;

    std::vector<Ball*> balls;
    std::vector<Sprite*> sprites;

    Player* player = win->CreatePlayer();
    sprites.push_back(player->GetSprite());

    std::vector<Brick*> bricks = gm->CreateBricks(win);
    for (auto brick : bricks) sprites.push_back(brick->GetSprite());

    for (size_t i = 0; i < 5; i++)
	{
		Ball* ball = win->CreateBall();
		balls.push_back(ball);
		sprites.push_back(ball->GetSprite());
	}

    PlayerInput* playerInput = win->InitPlayerInput();

	while (win->IsWindowCreated())
	{
        if (playerInput) playerInput->CheckMouse(player);
		for (auto ball : balls) ball->UpdatePos(W_WINDOW, H_WINDOW);
		win->Draw(sprites);
	}

    win->Kill();
    delete win;
    delete player;
    delete playerInput;

    for (auto sprite : sprites) delete sprite;
    sprites.clear();
    balls.clear();
    sprites.clear();

    return 0;
}