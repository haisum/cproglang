/*
Exercise 2-1. Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/

#include "stdio.h"
#include "limits.h"


int main(void){
    printf("%10s %30s %30s\n", "NAME", "MIN", "MAX");
    printf("%10s %30d %30d\n", "CHAR", CHAR_MIN , CHAR_MAX);
    printf("%10s %30d %30d\n", "UCHAR", 0 , UCHAR_MAX);
    printf("%10s %30d %30d\n", "SHORT", SHRT_MIN , SHRT_MAX);
    printf("%10s %30d %30d\n", "USHORT", 0, USHRT_MAX);
    printf("%10s %30d %30d\n", "INT", INT_MIN , INT_MAX);
    printf("%10s %30d %30u\n", "UINT", 0, UINT_MAX);
    printf("%10s %30ld %30ld\n", "LONG", LONG_MIN , LONG_MAX);
    printf("%10s %30d %30lu\n", "ULONG", 0 , ULONG_MAX);
}
