/*
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
Exercise 2-2. Write a loop equivalent to the for loop above without using && or || .
*/
#include "stdio.h"
#define MAX 100

void getLine(char s[]){
    int i;
    char c;
    for (i=0; i < MAX-2 ; ++i){
        c=getchar();
        if(c  == '\n' )
            i = MAX-2;// -2 because we need one char for \0
        else if (c == EOF)
            i = MAX-2;
        else
            s[i] = c;
    }
    s[++i] = '\0';
}

int main(void){
    char s[MAX];
    getLine(s);
    printf("%s\n", s);
    return 0;
}
