#pragma once

#define SDL_MAIN_HANDLED

#include "PlayerInput.h"
#include <SDL.h>

class PlayerInputSDL : public PlayerInput
{
public:
    void CheckMouse(Player* player) override; // M�thode pour g�rer le d�placement avec la souris
};