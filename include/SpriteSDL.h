#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class SpriteSDL : public Sprite
{
public:

	SpriteSDL(std::string path, SDL_Renderer* renderer);

	virtual void* Get() override { return (void*)&m_texture; }
	virtual int GetWidth() override { return m_size.first; }
	virtual int GetHeight() override { return m_size.second; }

private:

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	std::pair<int, int> m_size;
};