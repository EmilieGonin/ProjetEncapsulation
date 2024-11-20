#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string path, int x, int y, SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_path = path;
	m_pos = std::make_pair(x, y);

	SDL_Surface* buffer = IMG_Load(path.c_str());
	if (!buffer) return;

	m_texture = SDL_CreateTextureFromSurface(renderer, buffer);
	SDL_FreeSurface(buffer);
	buffer = NULL;
}