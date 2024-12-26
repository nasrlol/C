#include <stdio.h>

int summation(int num)
{
    int result = 0;
    int i = 0;
    if (num == 1)
    {

        return 1;
    }
    else
    {

        while (i <= num)
        {

            result += i;
            i++;
        }
        return result;
    }
}


int main()
{
    printf("%d", summation(8));

    return 0;
}

/*Write a program that finds the summation of every number from 1 to num. The number will always be a positive integer greater than 0. Your function only needs to return the result, what is shown between parentheses in the example below is how you reach that result and it's not part of it, see the sample tests.

For example (Input -> Output): */