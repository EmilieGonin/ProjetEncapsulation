#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string path, int x, int y, SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_path = path;
	m_pos = std::make_pair(x, y);
}

void SpriteSDL::Load()
{
}