/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
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
	int i, spaces;
	spaces = 0;
	for(i=0; i < MAX && (c = getchar()) != EOF && c != '\n' && c != '\r'; ++i){
		if(c == ' '){
			++spaces;
		}
		if (spaces == TABSPACES){
			spaces = 0;
			i = i - TABSPACES + 1;
			s[i] = '\t';
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