#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string path, SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_path = path;

	SDL_Surface* buffer = IMG_Load(path.c_str());
	if (!buffer) return;

	m_texture = SDL_CreateTextureFromSurface(renderer, buffer);
	SDL_FreeSurface(buffer);
	buffer = NULL;

	int width, height;
	SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);
	m_size = std::make_pair(width, height);
}