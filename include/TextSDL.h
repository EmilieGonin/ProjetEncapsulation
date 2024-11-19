#pragma once
#include "Text.h"
#include <SDL.h>
#include <SDL_ttf.h>

class TextSDL : public Text
{
public:
    TextSDL(SDL_Renderer* renderer);
    ~TextSDL();

    bool LoadFont(const std::string& fontPath, int fontSize);
    void RenderText(const std::string& text, int x, int y, SDL_Color color);
    void Cleanup();

private:
    SDL_Renderer* m_renderer;
    TTF_Font* m_font;
};