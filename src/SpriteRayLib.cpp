#include "SpriteRayLib.h"

SpriteRayLib::SpriteRayLib(std::string path)
{
	m_path = path;
	Load();
}

void SpriteRayLib::Load()
{
	m_texture = LoadTexture(m_path.c_str());
}

void* SpriteRayLib::Get()
{
	return (void*)&m_texture;
}