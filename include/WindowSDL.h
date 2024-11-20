#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include "Window.h"
#include "TextSDL.h"
#include "SpriteSDL.h"
#include <unordered_map>

class WindowSDL : public Window
{
public:

    virtual int InitLib() override;
    virtual int CreateWindow() override;
    virtual bool IsWindowCreated() override;
    virtual void Draw() override;
    virtual void Clear() override;
    virtual void Kill() override;

private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    TTF_Font* m_font = nullptr;
    TextSDL* m_fps = nullptr;

    // Cache des textures pour �viter de les recharger plusieurs fois
    std::unordered_map<std::string, SDL_Texture*> m_textureCache;

    // M�thode pour charger une texture � partir d'un fichier
    SDL_Texture* LoadTexture(const std::string& path);

    void CapFrameRate(int targetFPS);

    // M�thode pour obtenir le chemin complet des ressources
    std::string GetResourcePath(const std::string& filename);

    Uint32 m_lastFrameTime = 0;
};
