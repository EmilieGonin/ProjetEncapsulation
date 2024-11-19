#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

int main(int argc, char** args)
{
	Window* win = new WindowSDL();
	//Window* win = new WindowRayLib();

	if (win->InitLib()) return 1;
	if (win->CreateWindow()) return 1;

	//system("pause");

	while (win->IsWindowCreated())
	{
		win->Draw();
	}

	win->Kill();
	return 0;
}