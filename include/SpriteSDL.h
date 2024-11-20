#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class SpriteSDL : public Sprite
{
public:

	SpriteSDL(std::string path, int x, int y, SDL_Renderer* renderer);

	virtual void* Get() override { return (void*)&m_texture; }
	virtual int GetWidth() override;
	virtual int GetHeight() override;

private:

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};