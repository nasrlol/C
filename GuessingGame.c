#include <stdio.h>
#include <stdlib.h>

#define max 10
#define min 1

int main()
{

    printf("Number Guessing Game:\n");

    char buffer[100];

    int randNumb = rand() % (max - min + 1) + min;
    int guess = 0;

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &guess);

    if (guess == randNumb)
    {
        printf("The random number is %d\n", randNumb);
        printf("CORRECT\n");
        printf("you guessed %d", guess);
    }
    else
    {
        printf("The random number is %d\n", randNumb);
        printf("WRONG\n");
        printf("you guessed %d", guess);
    }

    return 0;
}
