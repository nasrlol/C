#include <stdio.h>
#include <stdlib.h> 

#define PASSWORD_LENGTH 8

char *generate_password()
{
    static char password[PASSWORD_LENGTH + 1]; 
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabet_size = sizeof(alphabet) - 1; 

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        int index = rand() % alphabet_size; 
        password[i] = alphabet[index];
    }
    password[PASSWORD_LENGTH] = '\0'; 

    return password;
}

int main()
{

    char *password = generate_password();
    printf("Generated Password: %s\n", password);

    return 0;
}