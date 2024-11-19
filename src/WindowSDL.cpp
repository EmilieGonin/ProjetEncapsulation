#include "WindowSDL.h"

int WindowSDL::InitLib()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;
	}

	// Initialiser SDL_ttf
	if (TTF_Init() == -1) 
	{
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		system("pause");
		return 1;
	}

	return 0;
}

int WindowSDL::CreateWindow()
{
	m_window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	if (!m_window) 
	{
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) 
	{
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Initialiser TextSDL
	m_text = new TextSDL(m_renderer);
	if (!m_text->LoadFont("font.ttf", 24)) return 1;

	Draw();

	return 0;
}

bool WindowSDL::IsWindowCreated()
{
	return m_window;
}

void WindowSDL::Draw()
{
	Uint32 startTicks = SDL_GetTicks();
	static Uint32 lastTicks = startTicks;
	static float fps = 0.0f;

	// Calcul FPS
	Uint32 currentTicks = SDL_GetTicks();
	fps = 1000.0f / (currentTicks - lastTicks);
	lastTicks = currentTicks;

	// Nettoyer l'écran
	SDL_SetRenderDrawColor(m_renderer, 25, 25, 112, 255);
	SDL_RenderClear(m_renderer);

	// Exemple d'affichage texte avec FPS
	SDL_Color color = { 0, 255, 0, 255 };
	m_text->RenderText("FPS: " + std::to_string((int)fps), 10, 10, color);

	// Coordonnées du centre du disque et son rayon
	int centerX = 320;  // Par exemple, au centre de la fenêtre
	int centerY = 240;
	int radius = 50;   // Rayon du disque

	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	// Parcourir tous les pixels dans un carré autour du cercle
	for (int y = centerY - radius; y <= centerY + radius; y++) 
	{
		for (int x = centerX - radius; x <= centerX + radius; x++) 
		{
			// Vérifier si le pixel est à l'intérieur du cercle
			if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) 
			{
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

	if (m_text) 
	{
		m_text->Cleanup();
		delete m_text;
		m_text = nullptr;
	}

	SDL_Quit();
}


