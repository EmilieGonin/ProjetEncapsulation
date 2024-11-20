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
	return 0;
}

bool WindowRayLib::IsWindowCreated()
{
	return !WindowShouldClose();
}

Ball* WindowRayLib::CreatePlayer()
{
	return new Ball(new SpriteRayLib("Pokeball.png", 400, 200));
}

Brick* WindowRayLib::CreateBrick(int x, int y)
{
	return new Brick(new SpriteRayLib("Pokeball.png", 400, 200), x, y);
}

void WindowRayLib::Draw(std::vector<Sprite*> sprites)
{
	BeginDrawing();
	Color background = { 25, 25, 112, 255 };
	ClearBackground(background);

	for (auto sprite : sprites)
	{
		Texture2D texture = *reinterpret_cast<Texture2D*>(sprite->Get());
		DrawTexture(texture, sprite->GetPos().first, sprite->GetPos().second, WHITE);
	}

	//DrawText("Hello Raylib", 200, 200, 20, WHITE);

	EndDrawing();
}

void WindowRayLib::Clear()
{
	/*for (auto sprite : m_sprites)
	{
		Texture2D texture = *reinterpret_cast<Texture2D*>(sprite->Get());
		UnloadTexture(texture);
	}*/
}

void WindowRayLib::Kill()
{
	CloseWindow();
}