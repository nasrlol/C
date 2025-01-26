/*
 * =====================================================================================
 *
 *       Filename:  order.c
 *
 *    Description: a codewars exercise 
 *
 *        Version:  1.0
 *        Created:  01/21/2025 22:49:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: nasr 
 *
 * =====================================================================================
 */
#include <stdlib.h>

void sort_by_length (const char *strings[])
{
    // strings[] is NULL-terminated
    // Re-use the pointers in 'strings', just change their order in the array
    // according to their length

    size_t length_array = sizeof(*strings) / sizeof(*strings[0]);

    for (int i = 0; i < (sizeof(*strings) / sizeof(*strings[0])) ; i++)
    {
        int count = 0; 
        while (*strings[i] != 0)
        {

        }
    }
}
