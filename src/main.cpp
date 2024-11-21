#include "Window.h"
#include "WindowSDL.h"
#include "PlayerInputSDL.h"
#include "WindowRayLib.h"
#include "PlayerInputRayLib.h"

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

    if (win->InitLib()) return 1;
    if (win->CreateWindow()) return 1;

    std::vector<Ball*> balls;
    std::vector<Sprite*> sprites;

    for (size_t i = 0; i < 5; i++)
	{
		Ball* ball = win->CreateBall();
		balls.push_back(ball);
		sprites.push_back(ball->GetSprite());
	}

    Player* player = win->CreatePlayer();
    sprites.push_back(player->GetSprite());

	//m_sprites.push_back(win->CreateBrick(1,1)->GetSprite()); //boucle for

    PlayerInput* playerInput = nullptr;

    if (dynamic_cast<WindowSDL*>(win)) {
        playerInput = new PlayerInputSDL(); // Utilisation de PlayerInputSDL pour SDL
    }
    else if (dynamic_cast<WindowRayLib*>(win)) {
        playerInput = new PlayerInputRayLib(); // Utilisation de PlayerInputRayLib pour Raylib
    }

	while (win->IsWindowCreated())
	{
		for (auto ball : balls)
		{
			ball->UpdatePos(W_WINDOW, H_WINDOW);
		}

        if (playerInput) {
            playerInput->CheckMouse(player); // Déplacement du paddle selon l'entrée de la souris
        }

		win->Draw(sprites);
	}

    win->Kill();
    delete win;
    delete player;
    delete playerInput;

    // clear sprites
    balls.clear();
    sprites.clear();

    return 0;
}