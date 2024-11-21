#include "WindowRayLib.h"

int WindowRayLib::InitLib()
{
	SetTargetFPS(60);
	SearchAndSetResourceDir("resources");
	return 0;
}

int WindowRayLib::CreateWindow()
{
	InitWindow(W_WINDOW, H_WINDOW, "Projet Encapsulation");
	m_font = LoadFont("Roboto-Regular.ttf");
	SetTextureFilter(m_font.texture, TEXTURE_FILTER_POINT);
	m_fps = new TextRayLib("", { 10, 10 });
	HideCursor();
	return 0;
}

bool WindowRayLib::IsWindowCreated()
{
	return !WindowShouldClose();
}

Player* WindowRayLib::CreatePlayer()
{
	SpriteRayLib* sprite = new SpriteRayLib("Paddle.png");
	int x = (W_WINDOW - sprite->GetWidth()) / 2;
	int y = (H_WINDOW - sprite->GetHeight()) - (sprite->GetHeight() / 2);

	return new Player(sprite, x, y);
}

Ball* WindowRayLib::CreateBall()
{
	return new Ball(new SpriteRayLib("Pokeball.png"));
}

Brick* WindowRayLib::CreateBrick(int x, int y, std::string filename)
{
	return new Brick(new SpriteRayLib(filename + ".png"), x, y);
}

void WindowRayLib::Draw(std::vector<Sprite*> sprites)
{
	m_fps->Update(TextFormat("FPS: %i", GetFPS()));

	BeginDrawing();
	Color background = { 25, 25, 112, 255 };
	ClearBackground(background);

	for (auto sprite : sprites)
	{
		Texture2D texture = *reinterpret_cast<Texture2D*>(sprite->Get());
		DrawTexture(texture, sprite->GetPos().first, sprite->GetPos().second, WHITE);
	}

	DrawTextEx(m_font, m_fps->GetValue().c_str(),
		{ (float)m_fps->GetPos().first, (float)m_fps->GetPos().second },
		22, 1, { 0, 255, 0, 255 });

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
	//unload font
	CloseWindow();
}