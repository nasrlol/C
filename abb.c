#include <stdio.h>
#include <ctype.h>

char *get_initials (const char *full_name, char initials[4])
{
    int second_letter = -1;

    for (int i = 0; full_name[i] != '\0'; i++)
    {
        if (full_name[i] == ' '){
            second_letter = i + 1;
            break;
        }
    }

    initials[0] = toupper(full_name[0]);
    initials[1] = '.';
    initials[2] = toupper(full_name[second_letter]);
    initials[3] = '\0';

    return initials; // return it
}
