#include "calculator.h"

/*
unsigned int multiply(int a, int b)
{
    return 0;
}
*/

/*
unsigned int multiply(int a, int b)
{
    return a*b;
}
*/

/*
int multiply(int a, int b)
{
    return a*b;
}
*/

int multiply(int a, int b)
{
    long long int res;
    res = ((long long int)a)*((long long int)b);

    if(res > __INT_MAX__)
        return __INT_MAX__;
    return (int)res;
}