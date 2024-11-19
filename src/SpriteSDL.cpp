#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string path, int x, int y, SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_path = path;
	m_pos = std::make_pair(x, y);

	// Load image (PNG) into surface
	SDL_Surface* buffer = IMG_Load(path.c_str());
	if (!buffer) {
		std::cout << "Error loading image Pokeball.png: " << SDL_GetError() << std::endl;
		return;
	}

	// Create texture
	m_texture = SDL_CreateTextureFromSurface(renderer, buffer);
	// Free surface as it's no longer needed
	SDL_FreeSurface(buffer);
	buffer = NULL;
	if (!m_texture)
	{
		std::cout << "Error : " << SDL_GetError() << std::endl;
	}
}

void SpriteSDL::Load()
{
}