#pragma once
#include "Player.h"
#include "Window.h"

class PlayerInput
{
public:
    virtual void CheckMouse(Player* player) = 0;
};