#pragma once

#include "Player.h"

class PlayerInput
{
public:

    virtual void CheckMouse(Player* player) = 0;

protected:

    int m_windowWidth;
};