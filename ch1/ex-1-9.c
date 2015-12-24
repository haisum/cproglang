/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
 */
#include "stdio.h"

main(){
	char c;
	int isBlank = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' && isBlank == 0){
			isBlank = 1;
			putchar(' ');
		}
		else if(c!= ' ') {
			putchar(c);
			isBlank = 0;
		}
	}
}