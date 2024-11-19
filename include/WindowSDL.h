#pragma once
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "Window.h"
#include "math.h"
#include "TextSDL.h"
#include "SpriteSDL.h"

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

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;	
	TextSDL* m_text;
};