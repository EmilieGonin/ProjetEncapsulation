#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

int main(int argc, char** args)
{
	Window* win = new WindowSDL();
	//Window* win = new WindowRayLib();

	if (win->InitLib()) return 1;
	if (win->CreateWindow()) return 1;

	while (win->IsWindowCreated())
	{
		win->Draw();
	}

	win->Kill();
	return 0;
}