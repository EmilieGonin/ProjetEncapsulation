#include "Brick.h"

Brick::Brick(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_sprite->SetPos(x, y);
}