#include "stdio.h"
#include "string.h"

#define MAX 20

void getLine(char s[]);
int hasNewLine(char s[]);

main(){
	char s[MAX];
	int lastNewline, i =0;
	getLine(s);
	while(s[0] != '\0'){
		for(i=0; i<strlen(s); i++){
			if(s[i] == '\n')
				lastNewline = 0;
			else
				++lastNewline;
			putchar(s[i]);
			if(lastNewline == MAX){
				putchar('\n');
				lastNewline = 0;
			}
		}
		getLine(s);
	}
}

int hasNewLine(char s[]){
	int i;
	for(i=0; i < strlen(s); ++i){
		if(s[i] == '\n')
			return 1;
	}
	return 0;
}

void getLine(char s[]){
	char c;
	int i, lastSpace;
	lastSpace = -1;
	for(i=0; i < MAX && (c = getchar()) != EOF && c != '\n'; ++i){
		if(c == ' '){
			lastSpace = i;
		}
		s[i] = c;
	}
	if(lastSpace >= 0){
		s[lastSpace] = '\n';
	}
	if ( c == '\n' ){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
}