#pragma once
#include "Text.h"
#include <SDL_pixels.h>

class TextSDL : public Text
{
public:
	TextSDL(std::string text, std::pair<int, int> pos, SDL_Color color);
	std::string GetValue();
	std::pair<int, int> GetPos();
	SDL_Color GetColor();

	void Update(std::string);

private:
	std::string m_text;
	std::pair<int, int> m_pos;
	SDL_Color m_color;
};