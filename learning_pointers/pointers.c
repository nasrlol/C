#include <stdio.h>

int main()
{

    int x = 4;
    int y = 8;

    int *pX = &x;
    y += *pX;

    // pointers in c
    printf("adress of x: %p\n", pX);
    printf("value at x: %d\n", *pX);
    printf("y: %d\n", y);


    // arrays in c
    int array[5] =  {0,1,2,3,4};
    printf("first element of array %d\n", array[0]);
    printf("sizeof array: %lu\n", sizeof(array));

    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
    {
        printf("ELEMENTS: %d\n", array[i]);
    }
    int size = 5;

    int *last_element = &array[size - 1];

    printf("ADDRESS: %p\n", last_element);
    printf("VALUE: %d\n", *last_element);

    for (int i = 0; i < (sizeof(array)/sizeof(array[9])); i++)
    {
        printf("pELEMENTS: %d\n", *(&array[0 + i]));
    }

    return 0;
}
