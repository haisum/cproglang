#include "stdio.h"

#define MAX 1000

int getLine(char s[]);

main(){
	char s[MAX];
	int i, lastPos;
	while((lastPos = getLine(s)) != 0){
		for(i=lastPos -1; i >= 0; --i){
			putchar(s[i]);
		}
	}
}

int getLine(char s[]){
	int lastPos;
	char c;
	for(lastPos = 0; lastPos < MAX && (c = getchar()) != EOF && c != '\n' && c != '\r'; ++lastPos){
		s[lastPos] = c;
	}
	if(c == '\n' || c == '\r'){
		s[lastPos] = '\n';
		++lastPos;
	}
	s[lastPos] = '\0';
	return lastPos;
}