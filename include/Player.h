#pragma once

#include "Entity.h"

class Player : public Entity
{
public:

	Player(Sprite* sprite);

	virtual void UpdatePos(int screenWidth, int screenHeight);

private:
	std::pair<int, int> GetRandomDirection();

	std::pair<int, int> m_direction;
};