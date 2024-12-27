#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// getting the player move
void player(int x, int y);

// getting the computer move
void computer();

// reseting the board
void reset_board();

// checking winning positions
void checkwinner();

// declaring the winner of the game based on the checkwinner() function
int score();

// globaly making the board 
char board[3][3];

int main()
{

    // making the board
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < i; j++){

            board[i][j] = '_';
        }
    }

    printf("OXO 1.0\n?");

    int x = 0;
    int y = 0;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y); 

    player(x, y);     
    player(x,y);

    return 0;
}



void player(int x, int y){
    
    board[x][y] = 'X';

}

void computer(){
    srand(time(0));

    int x = rand() % 3;
    int y = rand() % 3;

    printf("the computer placed O on %d %d", x, y);
}

void reset_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
}

void check_winner(){

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < i; j++){
            continue;
        };

    }        
};



