#include <raylib.h>
#include <stdio.h>
#include <raymath.h>

#define GREY LIGHTGRAY
#define POSX 200
#define POSY 200
#define HEIGTH 200
#define WIDTH 200

int main(void)
{
    InitWindow(800, 600, "flabbybird");
    HideCursor();

    ToggleFullscreen();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREY);
        DrawRectangle(POSX, POSY, WIDTH, HEIGTH, BLACK);
        DrawRectangle(POSX + 200, POSY , HEIGTH, WIDTH, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}