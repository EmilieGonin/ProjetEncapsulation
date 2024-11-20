#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

Player* m_player;
std::vector<Sprite*> m_sprites;

int main(int argc, char** args)
{
	Window* win = new WindowSDL();
	//Window* win = new WindowRayLib();

	if (win->InitLib()) return 1;
	if (win->CreateWindow()) return 1;

	m_player = win->CreatePlayer();

	m_sprites.push_back(m_player->GetSprite());
	m_sprites.push_back(win->CreateBrick(1,1)->GetSprite()); //boucle for

	while (win->IsWindowCreated())
	{
		m_player->UpdatePos(W_WINDOW, H_WINDOW);
		win->Draw(m_sprites);
	}

	win->Kill();
	return 0;
}