#include "TextSDL.h"

TextSDL::TextSDL(std::string text, std::pair<int, int> pos, SDL_Color color)
{
	m_value = text;
	m_pos = pos;
	//m_color = color;
}