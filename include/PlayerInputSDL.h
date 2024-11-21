#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "PlayerInput.h"

class PlayerInputSDL : public PlayerInput
{
public:

    virtual void CheckMouse(Player* player, int windowWidth) override;
};