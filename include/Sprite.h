#pragma once

#include <string>
#include <iostream>

class Sprite
{
public:

	virtual void Load() = 0;
	virtual void* Get() = 0;
	virtual std::pair<int, int> GetPos() { return m_pos; }

protected:

	std::string m_path;
	std::pair<int, int> m_pos;
};