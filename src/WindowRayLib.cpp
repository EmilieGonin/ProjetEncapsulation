#include "WindowRayLib.h"

int WindowRayLib::InitLib()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SearchAndSetResourceDir("resources");
	return 0;
}

int WindowRayLib::CreateWindow()
{
	InitWindow(W_WINDOW, H_WINDOW, "Projet Encapsulation");
	m_sprites.push_back(new SpriteRayLib("Pokeball.png", 400, 200));
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
		DrawTexture(texture, sprite->GetPos().first, sprite->GetPos().second, WHITE);
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