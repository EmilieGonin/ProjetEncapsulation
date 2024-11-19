#include "TextSDL.h"

//void TextSDL::RenderText(const std::string& text, int x, int y, SDL_Color color)
//{
//    SDL_Surface* surface = TTF_RenderText_Solid(m_font, text.c_str(), color);
//    if (!surface) 
//    {
//        std::cout << "Error creating text surface: " << TTF_GetError() << std::endl;
//        return;
//    }
//
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
//    if (!texture) 
//    {
//        std::cout << "Error creating text texture: " << SDL_GetError() << std::endl;
//        SDL_FreeSurface(surface);
//        return;
//    }
//
//    SDL_Rect destRect = { x, y, surface->w, surface->h };
//    SDL_RenderCopy(m_renderer, texture, NULL, &destRect);
//
//    SDL_FreeSurface(surface);
//    SDL_DestroyTexture(texture);
//}

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
