#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRayLib : public Sprite
{
public:

	SpriteRayLib(std::string path);

	virtual void* Get() override { return (void*)&m_texture; }
	virtual int GetWidth() override { return m_texture.width; }
	virtual int GetHeight() override { return m_texture.height; }

private:

	Texture2D m_texture;
};