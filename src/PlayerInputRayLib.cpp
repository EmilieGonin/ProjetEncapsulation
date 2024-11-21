#include "PlayerInputRayLib.h"

void PlayerInputRayLib::CheckMouse(Player* player, int windowWidth)
{
    int mouseX = GetMouseX();
    int newX = mouseX - player->GetSprite()->GetWidth() / 2;  // Centrer le paddle

    if (newX < 0) newX = 0;
    if (newX > windowWidth - player->GetSprite()->GetWidth()) newX = windowWidth - player->GetSprite()->GetWidth();

    auto currentPos = player->GetSprite()->GetPos();
    int newY = currentPos.second;

    player->SetPos(newX, newY);
}