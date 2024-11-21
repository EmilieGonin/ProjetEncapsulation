#pragma once

#include "PlayerInput.h"
#include "raylib.h"

class PlayerInputRayLib : public PlayerInput
{
public:

	PlayerInputRayLib(int w);

	virtual void CheckMouse(Player* player) override;
};