#pragma once

#include "PlayerInput.h"
#include "raylib.h"

class PlayerInputRayLib : public PlayerInput
{
public:

	virtual void CheckMouse(Player* player, int windowWidth) override;
};