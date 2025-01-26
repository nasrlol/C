/*
 * =====================================================================================
 *
 *       Filename:  camelcame.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/16/2025 12:53:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *      Author:  Abdellah El Morabit, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stddef.h> // NULL

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  
    if (sizeof(camelCase) == 0)
            return &camelCase;

    for (int i = 0; i < sizeof(camelCase); i++)
    {
        if(&(*camelCase + 1) == " ")
        {
            
        }
        else
        {
            return &camelCase;
        }
    }
}
