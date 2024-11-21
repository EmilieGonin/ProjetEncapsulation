#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(Sprite* sprite, int x, int y);
	void SetPos(int x, int y);
};