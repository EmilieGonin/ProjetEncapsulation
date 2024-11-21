#include "PlayerInputRayLib.h"

void PlayerInputRayLib::CheckMouse(Player* player)
{
    int mouseX = GetMouseX();
    int newX = mouseX - player->GetSprite()->GetWidth() / 2;  // Centrer le paddle

    if (newX < 0) newX = 0;
    if (newX > GetScreenWidth() - player->GetSprite()->GetWidth()) newX = GetScreenWidth() - player->GetSprite()->GetWidth();

    auto currentPos = player->GetSprite()->GetPos();
    int newY = currentPos.second;

    player->SetPos(newX, newY);
}