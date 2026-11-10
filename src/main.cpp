#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Tetris");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("TETRIS", 330, 250, 40, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}