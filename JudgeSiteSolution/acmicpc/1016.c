#include <stdio.h>
#include <math.h>
 
#define INT64 long long

int main()
{
    INT64 min, max;
    scanf("%llu %llu", &min, &max);
 
    INT64 A = (sqrtl(max) >= (INT64)sqrtl(max)) ? (INT64)sqrtl(max) + 1 : (INT64)sqrtl(max);
    INT64 B = (sqrtl(min) > (INT64)sqrtl(min)) ? (INT64)sqrtl(min) + 1 : (INT64)sqrtl(min);
    INT64 result = A - B;
         
    result = (max - min + 1) - result;
    printf("%llu\n", result);
    return 0;
}