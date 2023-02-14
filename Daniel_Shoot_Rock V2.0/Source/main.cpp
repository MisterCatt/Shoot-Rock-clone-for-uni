#include "raylib.h"
#include "ShootRock_Game.h"

int main(void)
{    
    const int screenWidth = 960;
    const int screenHeight = 960;

    InitWindow(screenWidth, screenHeight, "Shoot rock - Daniel Mardunovich, dama7895");
    InitAudioDevice();

    SetTargetFPS(60);

    ShootRock_Game* Game = new ShootRock_Game();
  
    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

        Game->Run();

        EndDrawing();
        
    }

    
    CloseAudioDevice();
    CloseWindow();

    delete Game;
    Game = nullptr;

    return 0;
}