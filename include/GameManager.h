#pragma once

#include <map>

#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

#define GRID_HEIGHT 8

class GameManager
{
public:

	std::vector<Brick*> CreateBricks(Window* win);

private:

	std::map<Element, std::string> m_elements =
	{
		{ Element::Fire, "Fire_Brick" },
		{ Element::Electrik, "Electrik_Brick" },
		{ Element::Water, "Water_Brick" },
		{ Element::Plant, "Plant_Brick" }
	};
};