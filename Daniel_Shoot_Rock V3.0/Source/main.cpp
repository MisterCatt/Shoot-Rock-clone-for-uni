#include "raylib.h"
#include "GameManager.h"
#include "Game.h"

int main(void)
{    
    const int screenWidth = 960;
    const int screenHeight = 960;

    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE | ConfigFlags::FLAG_VSYNC_HINT | ConfigFlags::FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "The Event Loop of Life");
    InitAudioDevice();

    SetTargetFPS(60); // Uncomment this if you want to use fixed framerate (I suggest using vsync)
    // SetExitKey(0);    // Uncomment this to disable ESC as exit key

    GameManager gm;

    static Texture2D Asteroid, SpaceShip, Star;
    static Sound ChargeSound, CoinPickupSound, DestructionSound, ShootSound;

    Asteroid = LoadTexture("Assets/Asteroid.png");
    SpaceShip = LoadTexture("Assets/SpaceShip.png");
    Star = LoadTexture("Assets/Star.png");

    ChargeSound = LoadSound("Assets/ChargeSound.wav");
    CoinPickupSound = LoadSound("Assets/CoinPickupSound.wav");
    DestructionSound = LoadSound("Assets/DestructionSound.wav");
    ShootSound = LoadSound("Assets/ShootSound.wav");

    gm.AddSound("Charge", ChargeSound);
    gm.AddSound("Coin", CoinPickupSound);
    gm.AddSound("Destruction", DestructionSound);
    gm.AddSound("Shoot", ShootSound);

    gm.AddTexture("Asteroid", Asteroid);
    gm.AddTexture("Player", SpaceShip);
    gm.AddTexture("Star", Star);

    Game ShootRock;

    ShootRock.AddGameManager(gm);

    while (!WindowShouldClose())
    {
        // Draw
        BeginDrawing();

        ShootRock.Run();

        EndDrawing();
    }

    UnloadTexture(Asteroid);
    UnloadTexture(SpaceShip);
    UnloadTexture(Star);

    UnloadSound(ChargeSound);
    UnloadSound(CoinPickupSound);
    UnloadSound(DestructionSound);
    UnloadSound(ShootSound);

    CloseAudioDevice();
    CloseWindow();
    
    return 0;
}