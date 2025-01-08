#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// GAME SETTINGS
#define FPS 30
#define FONT_SIZE 20

#define CYAN_I \
    (Color) { 0, 255, 255, 255 }
#define YELLOW_O \
    (Color) { 255, 255, 102, 255 }
#define PURPLE_T \
    (Color) { 138, 43, 226, 255 }
#define GREEN_S \
    (Color) { 34, 139, 34, 255 }
#define RED_Z \
    (Color) { 255, 69, 0, 255 }
#define BLUE_J \
    (Color) { 70, 130, 180, 255 }
#define ORANGE_L \
    (Color) { 255, 140, 0, 255 }

// Window and Grid Settings
static const int SCREEN_WIDTH = 400;
static const int SCREEN_HEIGHT = 600;
static const int COLUMNS = 10;
static const int ROWS = 20;
static const int CELL_WIDTH = SCREEN_WIDTH / COLUMNS;
static const int CELL_HEIGHT = SCREEN_HEIGHT / ROWS;

static int SCORE = 0;
static float DROP_INTERVAL = 0.0f;
static const float DROP_TIMEFRAME = 0.1f;

typedef struct
{
    int blocks[4][4];
    Color color;
    int x; 
    int y; 
} TETROMINO;

TETROMINO TETROMINOES[7] = {
    // Making the tetrominoes in an array design
    {
        {
            {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}}, CYAN_I, 0, 0},
    {
        {
            {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, YELLOW_O, 0, 0},
    {
        {
            {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, PURPLE_T, 0, 0},
    {
        {
            {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, GREEN_S, 0, 0},
    {
        {
            {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, RED_Z, 0, 0},
    {
        {
            {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, BLUE_J, 0, 0},
    {
        {
            {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, ORANGE_L, 0, 0},
};

void DRAW_GRID_BACKGROUND()
{
    for (int i = 0; i <= COLUMNS; i++)
    {
        DrawLine(i * CELL_WIDTH, 0, i * CELL_WIDTH, SCREEN_HEIGHT, GRAY);
    }
    for (int j = 0; j <= ROWS; j++)
    {
        DrawLine(0, j * CELL_HEIGHT, SCREEN_WIDTH, j * CELL_HEIGHT, GRAY);
    }
}

int **TETROMINOS_GRID(int rows, int columns)
{
    int **array = malloc(rows * sizeof(int *));
    if (!array)
        return NULL;

    for (int i = 0; i < rows; i++)
    {
        array[i] = calloc(columns, sizeof(int));
        if (!array[i])
        {
            for (int j = 0; j < i; j++)
                free(array[j]);
            free(array);
            return NULL;
        }
    }
    return array;
}

void FREE_GRID(int **array, int rows)
{
    for (int i = 0; i < rows; i++)
        free(array[i]);
    free(array);
}

void DRAW_TETROMINO(TETROMINO *tetromino)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (tetromino->blocks[y][x] == 1)
            {
                DrawRectangle(
                    (tetromino->x + x) * CELL_WIDTH,
                    (tetromino->y + y) * CELL_HEIGHT,
                    CELL_WIDTH, CELL_HEIGHT,
                    tetromino->color);
            }
        }
    }
}

TETROMINO SPAWN_TETROMINO()
{
    int RANDOM_INDEX = GetRandomValue(0, 6);
    TETROMINO tetromino = TETROMINOES[RANDOM_INDEX];
    tetromino.x = COLUMNS / 2 - 2;
    tetromino.y = 0;
    return tetromino;
}

void MOVE_TETROMINO(TETROMINO *tetromino)
{
    if (!IsKeyPressed(KEY_LEFT_SHIFT))
    {
        if (IsKeyPressed(KEY_RIGHT) && tetromino->x + 4 < COLUMNS + 1)
            tetromino->x++;
        if (IsKeyPressed(KEY_LEFT) && tetromino->x > 0)
            tetromino->x--;
        if (IsKeyDown(KEY_DOWN))
            tetromino->y++;
    }
}

void SAVE_TETROMINO(TETROMINO *tetromino, int **GRID)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (tetromino->blocks[y][x] == 1)
            {
                int GRIDX = tetromino->x + x;
                int GRIDY = tetromino->y + y;
                if (GRIDY < ROWS && GRIDX < COLUMNS)
                {
                    GRID[GRIDY][GRIDX] = 1;
                }
            }
        }
    }
}

void DRAW_SAVED_BLOCKS(int **GRID, TETROMINO *tetromino)
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLUMNS; x++)
        {
            if (GRID[y][x] == 1)
                DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, tetromino->color);
        }
    }
}

void DRAW_STATS()
{
    char SCORE_TEXT[16];
    sprintf(SCORE_TEXT, "Score: %d", SCORE);
    DrawText(SCORE_TEXT, 10, 10, FONT_SIZE, BLUE);
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    SetTargetFPS(FPS);

    TETROMINO ACTIVE_TETROMINO = SPAWN_TETROMINO();
    int **GRID = TETROMINOS_GRID(ROWS, COLUMNS);
    if (!GRID)
    {
        CloseWindow();
        return 1;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DRAW_GRID_BACKGROUND();
        DRAW_SAVED_BLOCKS(GRID, &ACTIVE_TETROMINO);
        DRAW_TETROMINO(&ACTIVE_TETROMINO);
        DRAW_STATS();

        DROP_INTERVAL += GetFrameTime();
        if (DROP_INTERVAL >= DROP_TIMEFRAME)
        {
            DROP_INTERVAL = 0.0f;
        }

        MOVE_TETROMINO(&ACTIVE_TETROMINO);

        if (ACTIVE_TETROMINO.y + 4 >= ROWS)
        {
            SAVE_TETROMINO(&ACTIVE_TETROMINO, GRID);
            ACTIVE_TETROMINO = SPAWN_TETROMINO();
        }

        EndDrawing();
    }

    FREE_GRID(GRID, ROWS);
    CloseWindow();
    return 0;
}