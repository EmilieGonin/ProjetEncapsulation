#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include <unordered_map>

#include "Window.h"
#include "TextSDL.h"
#include "SpriteSDL.h"
#include "PlayerInputSDL.h"

class WindowSDL : public Window
{
public:
    virtual int InitLib() override;
    virtual int CreateWindow() override;
    virtual bool IsWindowCreated() override;
    virtual PlayerInput* InitPlayerInput() override;
    virtual Player* CreatePlayer() override;
    virtual Ball* CreateBall() override;
    virtual Brick* CreateBrick(int x, int y, std::string filename) override;
    virtual void Draw(std::vector<Sprite*> sprites) override;
    virtual void Clear() override;
    virtual void Kill() override;

private:
    void CapFrameRate(int targetFPS);
    SDL_Texture* LoadTexture(const std::string& path);
    std::string GetResourcePath(const std::string& filename);
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    TTF_Font* m_font = nullptr;
    Uint32 m_lastFrameTime = 0;
    std::unordered_map<std::string, SDL_Texture*> m_textureCache;
};