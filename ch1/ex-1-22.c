#include "stdio.h"
#include "string.h"

#define MAX 20 //max length of line

void getLine(char s[]);
void printLine(char s[]);

main(){
	char s[MAX+2], c;// one for \n one for \0
	int i;
	getLine(s);
	while(s[0] != '\0'){
		printLine(s);
		getLine(s);
	}
}

void getLine(char s[]){
	char c;
	int i;
	for(i=0; i < MAX  && (c = getchar()) != EOF && c != '\n' && c != '\r'; ++i){
		s[i] = c;
	}
	if(c == '\r' || c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
}


void printLine(char s[]){
	char c;
	int lastPos, j;
	lastPos = strlen(s) - 1;
	for(j=lastPos; j >= 0 && s[j] != ' ' && s[j] != '\t'; --j)
			;
	if(j >= 0 && (s[j] == ' ' || s[j] == '\t'))
			s[j] = '\n';
	printf("%s", s);
	if(j >= 0 && s[j] == '\n'){
		while((c= getchar()) != EOF && c != '\n' && c != ' ' && c != '\t'){
			putchar(c);
		}
		if( c == ' ' || c == '\t'){
			putchar('\n');
		}
	}
}