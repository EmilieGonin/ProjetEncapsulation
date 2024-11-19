#include "TextSDL.h"

TextSDL::TextSDL(SDL_Renderer* renderer) : m_renderer(renderer), m_font(nullptr) 
{
    // Assurer que SDL_ttf est initialisé avant d'utiliser TTF_OpenFont
    if (TTF_Init() == -1) std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
}

TextSDL::~TextSDL()
{
	Cleanup();
}

bool TextSDL::LoadFont(const std::string& fontPath, int fontSize)
{
    if (!m_font) 
    {
        std::string fontPath = "C:/Users/aphilippe/Documents/GitHub/ProjetEncapsulation/resources/Roboto-Regular.ttf";  // Chemin relatif
        m_font = TTF_OpenFont(fontPath.c_str(), fontSize);
        if (!m_font) 
        {
            std::cout << "Error loading font: " << TTF_GetError() << std::endl;
            return false;
        }
    }
    return true;
}

void TextSDL::RenderText(const std::string& text, int x, int y, SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(m_font, text.c_str(), color);
    if (!surface) 
    {
        std::cout << "Error creating text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture) 
    {
        std::cout << "Error creating text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(m_renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void TextSDL::Cleanup()
{
    if (m_font) 
    {
        TTF_CloseFont(m_font);
        m_font = nullptr;
    }
}