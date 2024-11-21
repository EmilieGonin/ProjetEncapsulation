#pragma once
#include "PlayerInputSDL.h"

void PlayerInputSDL::CheckMouse(Player* player)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_MOUSEMOTION)  // Mouvement de la souris
        {
            int newX = event.motion.x - player->GetSprite()->GetWidth() / 2; // Centrer le paddle

            if (newX < 0) newX = 0;
            if (newX > W_WINDOW - player->GetSprite()->GetWidth()) newX = W_WINDOW - player->GetSprite()->GetWidth();

            auto currentPos = player->GetSprite()->GetPos();
            int newY = currentPos.second;

            player->SetPos(newX, newY);
        }
    }
}