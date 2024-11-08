#include <stdio.h>

int main(){
     double nc;
     nc = 0;

     while(getchar() != EOF){
          ++nc;
     }
     printf("%lf",nc);
     
     return 0;
}