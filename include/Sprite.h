#pragma once

#include <string>

class Sprite
{
public:

	virtual void Load() = 0;
	virtual void* Get() = 0;

protected:

	std::string m_path;
};