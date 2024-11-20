#include "SpriteRayLib.h"

SpriteRayLib::SpriteRayLib(std::string path)
{
	m_path = path;
	m_texture = LoadTexture(m_path.c_str());
}

int SpriteRayLib::GetWidth()
{
	return m_texture.width;
}

int SpriteRayLib::GetHeight()
{
	return m_texture.height;
}