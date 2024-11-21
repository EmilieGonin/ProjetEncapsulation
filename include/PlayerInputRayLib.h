#pragma once
#include "PlayerInput.h"
#include "raylib.h"

class PlayerInputRayLib : public PlayerInput
{
public:
	void CheckMouse(Player* player) override;
};