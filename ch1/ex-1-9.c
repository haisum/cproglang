#include "stdio.h"

main(){
	char c;
	int isBlank = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' && isBlank == 0){
			isBlank = 1;
			printf(" ");
		}
		else if(c!= ' ') {
			printf("%c", c);
			isBlank = 0;
		}
	}
}