#include <stdio.h>


int add(int x, int y){

    return x + y;
}

int sub(int x, int y){
    
    return x - y;
}

int mult(int x, int y){

    return x * y;
}

int div(int x, int y){
    
    return x / y;
}


int main(){

    int num1, num2;
    char operator;

    printf("Enter the first number:\n");
    scanf("%d", &num1);    

    printf("Enter the second number:\n");
    scanf("%d", &num2);
    
    printf("Enter the operator:\n");
    scanf(" %c", &operator);

    switch (operator){ 

        case '+':
            printf("The result is %d\n", add(num1, num2));
            break;
        case '-':
            printf("The result is %d\n", sub(num1, num2));
            break;
        case '*':
            printf("The result is %d\n", mult(num1, num2));
            break;
        case '/':
            printf("The result is %d\n", div(num1, num2));
            break;
    }
    return 0;
}
