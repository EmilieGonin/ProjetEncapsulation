#include "GameManager.h"

std::vector<Brick*> GameManager::CreateBricks(Window* win)
{
    std::vector<Brick*> bricks;
    std::vector<std::pair<Element, std::string>> elements(m_elements.begin(), m_elements.end());

    Brick* brick = win->CreateBrick(0, 0, elements[0].second);
    Sprite* sprite = brick->GetSprite();

    int spacing = 2;
    int topSpacing = sprite->GetHeight() * 2;
    int nbBricksPerRow = W_WINDOW / (sprite->GetWidth() + spacing);
    int remainingSpace = W_WINDOW - (nbBricksPerRow * (sprite->GetWidth() + spacing));
    int offset = remainingSpace / 2;

    int xGrid, yGrid, elementIndex = 0;

    delete brick;

    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        xGrid = offset;

        for (size_t j = 0; j < nbBricksPerRow; j++)
        {
            if (elementIndex >= elements.size()) elementIndex = 0;
            yGrid = ((sprite->GetHeight() + 2) * i) + topSpacing;

            Brick* brick = win->CreateBrick(xGrid, yGrid, elements[elementIndex].second);
            Sprite* sprite = brick->GetSprite();
            bricks.push_back(brick);

            xGrid += sprite->GetWidth() + spacing;
        }

        elementIndex++;
        if (elementIndex >= elements.size()) elementIndex = 0;
    }

    return bricks;
}