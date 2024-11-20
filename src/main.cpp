#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

int main(int argc, char** args)
{
    Window* win = nullptr;

    if (argc > 1) {
        std::string arg = args[1];

        if (arg == "--raylib") {
            win = new WindowRayLib();  // Utilisation de Raylib
        }
        else if (arg == "--sdl") {
            win = new WindowSDL();     // Utilisation de SDL
        }
        else {
            std::cerr << "Argument inconnu : " << arg << std::endl;
            std::cerr << "Utilisez --raylib ou --sdl" << std::endl;
            return 1;
        }
    }
    else {
        win = new WindowSDL();
        //win = new WindowRayLib();
    }

    if (win->InitLib()) return 1;
    if (win->CreateWindow()) return 1;

    // Boucle principale
    while (win->IsWindowCreated()) 
    {
        win->Draw();
    }

    win->Kill();
    delete win;

    return 0;
}