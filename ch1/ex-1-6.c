/*
Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 */
#include "stdio.h"

main(){
	char c;
	while((c = getchar()) && c != EOF){
		if((c == EOF) != 0){
			printf("Fail! c == EOF is not zero\n");
		}
	}
	if((c == EOF) != 1){
			printf("Fail! c == EOF is not one after loop exit\n");
	}
}