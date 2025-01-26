#include <stdio.h>
#include <stdlib.h>

int no_boring_zeros(int n){
    
    int buffersize = snfprintf(NULL, 0, "%d", n) + 1;
    char *str = (char *)malloc(buffersize);
    
    snprintf(str, buffersize, "%d", n);

    for (int i = 0; i <= (sizeof(str)/sizeof(str[0]); i++){

            if (str[sizeof(str) - i] == 0 ){

                (*size)--;

            } else {

                break;
            }
    }       
    

}
