/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
 */
#include "stdio.h"

#define MAX 1000
#define MIN 80

double getLine(char s[]);

main(){
	double lineLength;
	char line[MAX];
	while((lineLength = getLine(line)) > 0){
		if(lineLength > MIN){
			printf("%s\n", line);
		}
	}
}

double getLine(char s[]){
	char c;
	double count = 0;
	int i;
	for(i=0; i < MAX - 1 && ((c = getchar()) != EOF && c != '\n' && c != '\r'); ++i){
		++count;
		s[i] = c;
	}
	s[++i] = '\0'; //always end strings with null char
	if(c == '\n' || c == '\r'){
		++count;
	}
	return count;
}