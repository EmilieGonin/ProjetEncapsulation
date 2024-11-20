#include "Player.h"

Ball::Ball(Sprite* sprite)
{
	m_sprite = sprite;
	m_sprite->SetPos(200, 200);
	m_direction = GetRandomDirection();
}

void Ball::UpdatePos(int screenWidth, int screenHeight)
{
	int x = m_sprite->GetPos().first;
	int y = m_sprite->GetPos().second;

	if (x <= 0 || x + m_sprite->GetWidth() >= screenWidth)
	{
		m_direction.first = -m_direction.first;
	}

	if (y <= 0 || y + m_sprite->GetHeight() >= screenHeight)
	{
		m_direction.second = -m_direction.second;
	}

	x += m_direction.first;
	y += m_direction.second;

	m_sprite->SetPos(x, y);
}

std::pair<int, int> Ball::GetRandomDirection()
{
	return std::make_pair(std::rand() % 5 + 1, std::rand() % 5 + 1);
}