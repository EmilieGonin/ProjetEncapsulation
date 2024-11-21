#pragma once

#define SDL_MAIN_HANDLED

#include "PlayerInput.h"
#include <SDL.h>

class PlayerInputSDL : public PlayerInput
{
public:
    void CheckMouse(Player* player) override; // Méthode pour gérer le déplacement avec la souris
};