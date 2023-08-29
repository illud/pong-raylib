#include <iostream>
#include "raylib.h"


int main()
{
    InitWindow(800, 600, "Pong");

    // v-sync
    SetWindowState(FLAG_VSYNC_HINT);

    // Ball position
    float ballX = GetScreenWidth() / 2.0f;
    float ballY = GetScreenHeight() / 2.0f;
    float ballRaduis = 8;

    float ballSpeedX = 100;
    float ballSpeedY = 300;

    while (!WindowShouldClose()) {
        ballX += ballSpeedX * GetFrameTime();
        ballY += ballSpeedY * GetFrameTime();

        if (ballY < 0) {
            ballY = 0;
            ballSpeedY *= -1;
        }

        if (ballY > GetScreenHeight()) {
            ballY = GetScreenHeight();
            ballSpeedY *= -1;
        }

        BeginDrawing();
         ClearBackground(BLACK);

         DrawCircle((int) ballX, (int) ballY, ballRaduis, WHITE);
         DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
         DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);

         DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
