#include "TextSDL.h"

TextSDL::TextSDL(std::string text, std::pair<int, int> pos, SDL_Color color)
{
	m_text = text;
	m_pos = pos;
	m_color = color;
}

std::string TextSDL::GetValue()
{
	return m_text;
}

std::pair<int, int> TextSDL::GetPos()
{
	return m_pos;
}

SDL_Color TextSDL::GetColor()
{
	return m_color;
}

void TextSDL::Update(std::string text)
{
	m_text = text;
}
