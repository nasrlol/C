#include <stdio.h>

const char* greet(const char *name, const char *owner) {

  
  if (name == owner){
    
    return "Hello boss";
  } else {
    return "Hello guest";
  }
  
  
  
}

int main(){

    printf("%s",greet("man", "man"));
    printf("%s",greet("hans","man"));
    return 0;
}
