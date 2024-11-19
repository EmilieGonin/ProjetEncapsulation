#include "WindowRayLib.h"

int WindowRayLib::InitLib()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SearchAndSetResourceDir("resources");
	return 0;
}

int WindowRayLib::CreateWindow()
{
	InitWindow(1280, 800, "Hello Raylib");
	m_sprites.push_back(new SpriteRayLib("wabbit_alpha.png"));
	return 0;
}

bool WindowRayLib::IsWindowCreated()
{
	return !WindowShouldClose();
}

void WindowRayLib::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (auto sprite : m_sprites)
	{
		Texture2D texture = *reinterpret_cast<Texture2D*>(sprite->Get());
		DrawTexture(texture, 400, 200, WHITE);
	}

	//DrawText("Hello Raylib", 200, 200, 20, WHITE);

	EndDrawing();
}

void WindowRayLib::Clear()
{
	for (auto sprite : m_sprites)
	{
		Texture2D texture = *reinterpret_cast<Texture2D*>(sprite->Get());
		UnloadTexture(texture);
	}
}

void WindowRayLib::Kill()
{
	CloseWindow();
}