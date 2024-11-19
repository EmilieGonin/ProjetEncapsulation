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

	// Initialize SDL_image with PNG loading subsystem
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		std::cout << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
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

	std::string fontPath = "../../resources/Roboto-Regular.ttf";
	m_font = TTF_OpenFont(fontPath.c_str(), 20);
	if (!m_font)
	{
		std::cout << "Error loading font: " << TTF_GetError() << std::endl;
		return false;
	}

	// Initialiser TextSDL
	m_fps = new TextSDL("", std::make_pair(10,10), { 0, 255, 0, 255 });

	m_sprites.push_back(new SpriteSDL("../../resources/Pokeball.png", 400, 200, m_renderer));

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

	m_fps->Update("FPS: " + std::to_string((int)fps));

	// Nettoyer l'�cran
	SDL_SetRenderDrawColor(m_renderer, 25, 25, 112, 255);
	SDL_RenderClear(m_renderer);


	SDL_Surface* surface = TTF_RenderText_Solid(m_font, m_fps->GetValue().c_str(), m_fps->GetColor());
	if (!surface)
	{
		std::cout << "Error creating text surface: " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	if (!texture)
	{
		std::cout << "Error creating text texture: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(surface);
		return;
	}

	SDL_Rect destRect = {m_fps->GetPos().first, m_fps->GetPos().second, surface->w, surface->h};
	SDL_RenderCopy(m_renderer, texture, NULL, &destRect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	for (auto sprite : m_sprites)
	{
		SDL_Rect destRect = { sprite->GetPos().first, sprite->GetPos().second, 100, 100 };

		SDL_Texture* texture = *reinterpret_cast<SDL_Texture**>(sprite->Get());

		SDL_RenderCopy(m_renderer, texture, NULL, &destRect);
	}

	// Limitation à 60 FPS
	Uint32 frameTicks = SDL_GetTicks() - startTicks;
	if (frameTicks < 1000 / 60) 
	{
		SDL_Delay(1000 / 60 - frameTicks);
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
	//SDL_DestroyTexture(m_texture);

	m_window = NULL;
	m_renderer = NULL;
	m_sprites.clear();

	if (m_fps) 
	{
		if (m_font)
		{
			TTF_CloseFont(m_font);
			m_font = NULL;
		}
		delete m_fps;
		m_fps = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}