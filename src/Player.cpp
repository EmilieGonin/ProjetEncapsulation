#include "Player.h"

Player::Player(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_sprite->SetPos(x, y);
}