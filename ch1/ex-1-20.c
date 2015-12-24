/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
 */
#include "stdio.h"

#define MAX 1000
#define TABSPACES 4

void getLine(char s[]);

main(){
	char s[MAX];
	getLine(s);
	while(s[0] != '\0'){
		printf("%s", s);
		getLine(s);
	}
}

void getLine(char s[]){
	char c;
	int i, j;
	for(i=0; i < MAX && (c = getchar()) != EOF && c != '\n' && c != '\r'; ++i){
		if(c == '\t'){
			for (j=0; j < TABSPACES; ++j){
				s[i + j] = ' ';
			}
			i = i + TABSPACES - 1;
		}
		else {
			s[i] = c;
		}
	}
	if ( c == '\n' || c == '\r' ){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
}