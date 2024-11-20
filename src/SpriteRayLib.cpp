#include "SpriteRayLib.h"

SpriteRayLib::SpriteRayLib(std::string path)
{
	m_path = path;
	m_texture = LoadTexture(m_path.c_str());
}