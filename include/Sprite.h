#pragma once

#include <string>
#include <iostream>

class Sprite
{
public:

	virtual void* Get() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	std::pair<int, int> GetPos() const { return m_pos; }

	void SetPos(int directionX, int directionY);

protected:

	std::string m_path;
	std::pair<int, int> m_pos;
};