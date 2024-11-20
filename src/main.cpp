#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

std::vector<Ball*> m_balls;
std::vector<Sprite*> m_sprites;

int main(int argc, char** args)
{
	std::srand(std::time(nullptr));

	//Window* win = new WindowSDL();
	Window* win = new WindowRayLib();

	if (win->InitLib()) return 1;
	if (win->CreateWindow()) return 1;

	for (size_t i = 0; i < 5; i++)
	{
		Ball* ball = win->CreatePlayer();
		m_balls.push_back(ball);
		m_sprites.push_back(ball->GetSprite());
	}

	//m_sprites.push_back(win->CreateBrick(1,1)->GetSprite()); //boucle for

	while (win->IsWindowCreated())
	{
		for (auto ball : m_balls)
		{
			ball->UpdatePos(W_WINDOW, H_WINDOW);
		}

		win->Draw(m_sprites);
	}

	win->Kill();
	return 0;
}