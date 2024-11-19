#pragma once

#include <SDL.h>
#include "Sprite.h"

class SpriteSDL : public Sprite
{
public:

	SpriteSDL(std::string path, SDL_Renderer* renderer);

	virtual void Load() override;
	virtual void* Get() override;

private:

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};