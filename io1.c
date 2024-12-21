#include <stdio.h>
#include <string.h> 

int main() {

    int input;
    char passcode[] = "nice";    
    char answer[] = "correct"; 

    printf("Enter a character: ");
    input = getchar(); 

    if (input == passcode[0]) {
        printf("%s\n", answer);
    } else {
        printf("Incorrect\n");
    }

    return 0;
}