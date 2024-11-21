#pragma once

#include "Entity.h"

enum class Element
{
	Fire,
	Electrik,
	Water,
	Plant
};

class Brick : public Entity
{
public:
	Brick(Sprite* sprite, int x, int y);
};