#include "stdio.h"

#define OUT 0
#define IN 1

main(){
	char c;
	int state = OUT;

	while((c = getchar()) != EOF){
		if (c == '\t' || c == '\n' || c == '\r' || c == ' '){ // \r is needed for windows files
			if (state == IN){
				putchar('\n');
			}
			state = OUT;
		} else {
			putchar(c);
			state = IN;
		}
	}
}