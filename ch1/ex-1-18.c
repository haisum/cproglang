#include "stdio.h"
#include "string.h"

#define MAX 1000

int getLine(char s[]);
int start(char s[]);
int end(char s[]);

main(){
	char s[MAX];
	int i;
	while(getLine(s) >= 1){
		for(i=start(s); i <= end(s); ++i){
			putchar(s[i]);
		}
		if(s[0] != '\n'){
			putchar('\n');
		}
	}
}

int getLine(char s[]){
	char c;
	int i;
	int length = 0;
	for(i=0;i < MAX - 1 && (c = getchar()) && c != EOF && c != '\r' && c != '\n'; ++i){
		s[i] = c;
		++length;
	}
	if(c == '\n' || c == '\r'){
		s[i] = '\n';
		++i;
		++length;
	}
	s[i] = '\0';
	return length;
}

int start(char s[]){
	int start;
	for(start=0; start < strlen(s) && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n' || s[start] == '\r'); ++start)
		;
	return start;
}

int end(char s[]){
	int end;
	for(end=strlen(s) - 1; end >= 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n' || s[end] == '\r'); --end)
		;
	return end;
}