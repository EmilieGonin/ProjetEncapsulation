#pragma once

#include "Player.h"

class PlayerInput
{
public:

    virtual void CheckMouse(Player* player, int windowWidth) = 0;
};