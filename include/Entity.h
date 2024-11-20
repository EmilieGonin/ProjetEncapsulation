#pragma once

#include "Sprite.h"

class Entity
{
public:
	Sprite* GetSprite() { return m_sprite; }

protected:

	Sprite* m_sprite;
};