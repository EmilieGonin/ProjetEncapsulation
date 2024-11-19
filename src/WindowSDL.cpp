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

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		return 1;
	}

	return 0;
}

bool WindowSDL::IsWindowCreated()
{
	return m_window;
}

void WindowSDL::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_Rect r;
	r.x = 150;
	r.y = 25;
	r.h = 75;
	r.w = 120;
	SDL_RenderFillRect(m_renderer, &r); // Draw a filled rectangle

	// Coordonnées du centre du disque et son rayon
	int centerX = 320;  // Par exemple, au centre de la fenêtre
	int centerY = 240;
	int radius = 100;   // Rayon du disque

	SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
	// Parcourir tous les pixels dans un carré autour du cercle
	for (int y = centerY - radius; y <= centerY + radius; y++) {
		for (int x = centerX - radius; x <= centerX + radius; x++) {
			// Vérifier si le pixel est à l'intérieur du cercle
			if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) {
				// Dessiner le point à cette position
				SDL_RenderDrawPoint(m_renderer, x, y);
			}
		}
	}
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
	m_renderer = NULL;

	SDL_Quit();
}