#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string path, SDL_Renderer* renderer) : m_renderer(renderer)
{
	m_path = path;
}

void SpriteSDL::Load()
{
}

void* SpriteSDL::Get()
{
	return (void*)&m_texture;
}