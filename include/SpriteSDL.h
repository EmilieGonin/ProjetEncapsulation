#pragma once

#include <SDL.h>
#include "Sprite.h"

class SpriteSDL : public Sprite
{
public:

	SpriteSDL(std::string path, int x, int y, SDL_Renderer* renderer);

	virtual void Load() override;
	virtual void* Get() override { return (void*)&m_texture; }

private:

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};