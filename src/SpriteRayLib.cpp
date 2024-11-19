#include "SpriteRayLib.h"

SpriteRayLib::SpriteRayLib(std::string path, int x, int y)
{
	m_path = path;
	m_pos = std::make_pair(x, y);
	Load();
}

void SpriteRayLib::Load()
{
	m_texture = LoadTexture(m_path.c_str());
}