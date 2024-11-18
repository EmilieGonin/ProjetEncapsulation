#include "WindowSDL.h"

int WindowSDL::InitLib()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}
	return 0;
}

int WindowSDL::CreateWindow()
{
	m_window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	// Make sure creating the window succeeded
	if (!m_window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	//m_winSurface = SDL_GetWindowSurface(m_window);
	//// Make sure getting the surface succeeded
	//if (!m_winSurface) {
	//	std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
	//	system("pause");
	//	// End the program
	//	return 1;
	//}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		return 1;
	}


	Draw();

	return 0;
}

bool WindowSDL::IsWindowCreated()
{
	return m_window;
}

void WindowSDL::Draw()
{
	//SDL_FillRect(m_winSurface, NULL, SDL_MapRGB(m_winSurface->format, 255, 0, 0));

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	SDL_Rect r;
	r.x = 150;
	r.y = 25;
	r.h = 75;
	r.w = 120;

	SDL_RenderFillRect(m_renderer, &r); // Draw a filled rectangle

	//SDL_UpdateWindowSurface(m_window);

	SDL_RenderPresent(m_renderer);

}

void WindowSDL::Clear()
{
	SDL_RenderClear(m_renderer);
}

void WindowSDL::Kill()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	m_window = NULL;
	m_winSurface = NULL;
	m_renderer = NULL;

	SDL_Quit();
}


