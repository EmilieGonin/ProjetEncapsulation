#pragma once

#include <SDL_pixels.h>
#include "Text.h"

class TextSDL : public Text
{
public:

	TextSDL(std::string text, std::pair<int, int> pos, SDL_Color color);

	//SDL_Color GetColor() const { return m_color; }

private:

	//SDL_Color m_color;
};