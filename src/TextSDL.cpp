#include "TextSDL.h"

TextSDL::TextSDL(std::string text, std::pair<int, int> pos, SDL_Color color)
{
	m_text = text;
	m_pos = pos;
	m_color = color;
}

void TextSDL::Update(std::string text)
{
	m_text = text;
}