#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// GAME FPS
#define FPS 60

// SHAPE COLORS
#define CYAN_I CYAN       // VERTICAL LINE OR SOMETHING
#define YELLOW_O YELLOW   // SQUARE
#define PURPLE_T PURPLE // HORIZONTAL LINE AND THEN ONE DOWN
#define GREEN_S GREEN     // Z-SHAPE LIKE THING
#define RED_Z RED         // GREEN BUT REVERSED
#define BLUE_J BLUE       // A REVERSED L
#define ORANGE_L ORANGE   // A NORMAL L

int BLOCKS[7][4][4] = {
    {
        // I
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    },
    {
        // O
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        // T
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    },
    {
        // S
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    },
    {
        // Z
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
    },
    {
        // J
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
    },
    {
        // L
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
    },
};

void DRAW_GRID(int rows, int columns, int cell_width, int cell_height, int screen_width, int screen_height)
{
    for (int i = 0; i <= columns; i++)
    {
        float x = i * cell_width;
        DrawLine((int)x, 0, (int)x, screen_height, GRAY);
    }
    for (int j = 0; j <= rows; j++)
    {
        float y = j * cell_height;
        DrawLine(0, (int)y, screen_width, (int)y, GRAY);
    }
}

void SPAWN_FIGURE(int BLOCKS[7][4][4], int SCREEN_HEIGHT, int SCREEN_WIDTH, int CELL_WIDTH, int CELL_HEIGHT, int FIGURE)
{
    int START_X, START_Y;
    int X_MAX, X_MIN, Y_MAX, Y_MIN;
    // definign the block size to draw it, still not sure on how do draw it though because the grid is from the top left down
    int BLOCK_SIZE;

    // set the limits for spawning a block
    X_MIN = 0;
    X_MAX = SCREEN_WIDTH;
    Y_MIN = 0;
    Y_MAX = 0;

    // set the seed for srand to generate a random coördinate
    srand(time(NULL));

    START_X = rand() % ((X_MAX - X_MIN) + 1) + X_MIN;
    START_Y = 2;

    BLOCK_SIZE = 4;

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (BLOCKS[FIGURE][y][x] == 1)
            {
                DrawRectangle(START_X + x * CELL_WIDTH, START_Y + y * CELL_HEIGHT + 1, CELL_WIDTH, CELL_HEIGHT + 1, BLUE);
            }
        }
    }
}

void MOVEMENT(int START_X, int START_Y)
{

    if (IsKeyDown(KEY_RIGHT))
        START_X += 1.0f;
    if (IsKeyDown(KEY_LEFT))
        START_X -= 1.0f;
    if (IsKeyDown(KEY_UP))
        START_Y += 1.0f;
    if (IsKeyDown(KEY_DOWN))
        START_Y -= 1.0f;
}

int CHECK_LINE_WIN()
{
    // checking for a full line and for every full line assing a point
    
    int POINT;
    POINT = 0;

    return POINT;
}

int HIGH_SCORE(int CHECK_LINE_WIN)
{

    // getting the poins from the CHECK_LINE_WIN function and adding them to the final score
    int FINAL_SCORE;
    FINAL_SCORE += CHECK_LINE_WIN;

    return FINAL_SCORE;
}

int main(void)
{

    // Initialize the window, use a 400 x 600 resolution
    const int screen_width = 400;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "Tetris");
    // Set the target fps of the game
    SetTargetFPS(FPS);

    // disable and hide the cursor input to force keyboard use
    HideCursor();

    // get the measurements for the grid
    // a default tetris grid should be 40 x 10
    const int columns = 10;
    const int rows = 20;

    const float cell_width = (float)screen_width / columns;
    const float cell_height = (float)screen_height / rows;

    srand(time(NULL));
    typedef enum 
        {
            I,
            O,
            T,
            S,
            Z,
            J,
            L} FIGURE;

    int NUM_SHAPES;
    NUM_SHAPES = 6;
    FIGURE RANDOM_FIGURE = (FIGURE)(rand() % NUM_SHAPES);

    while (!WindowShouldClose())
    {
        // initiaze drawing
        BeginDrawing();
        // set the background color
        ClearBackground(BLACK);

        // draw the grid in the background to place blocks on it afterwards
        DRAW_GRID(rows, columns, cell_width, cell_height, screen_width, screen_height);

        // spawn the tetronomes 
        SPAWN_FIGURE(BLOCKS, screen_height, screen_width, cell_width, cell_height, RANDOM_FIGURE);

        // finish and stop drawing 
        EndDrawing();
    }

    // unitiialize the window
    CloseWindow();

    return 0;
}