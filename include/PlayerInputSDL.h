#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "PlayerInput.h"

class PlayerInputSDL : public PlayerInput
{
public:

    PlayerInputSDL(int w);

    virtual void CheckMouse(Player* player) override;
};