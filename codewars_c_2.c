#include <stdbool.h>

bool is_pangram(const char *str_in)
{
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    char split_alphabet[26] = strtok(alphabet, "");
    char split_string[26] = strtok(str_in, "");
    int correct_char = 0;
    for (int i = 0; i < (sizeof(split_string) / sizeof(split_string[0])); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (split_string[i] == split_alphabet[j])
            {
                correct_char++;
            }
        }
        if (correct_char == 26)
        {
            return true;
        }
        else
        {

            return false;
        }
    }
}
