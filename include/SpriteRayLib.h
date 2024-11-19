#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRayLib : public Sprite
{
public:

	SpriteRayLib(std::string path);

	virtual void Load() override;
	virtual void* Get() override;

private:

	Texture2D m_texture;
};