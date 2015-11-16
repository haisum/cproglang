#include "stdio.h"

#define OUT 0
#define IN 1
#define MAX 1000

main(){
	char c;
	int state = OUT;
	int counts[MAX];
	int count, i, j;
	count =i = j = 0;
	//initialize counts
	for (i=0; i < MAX; i++){
		counts[i] = 0;
	}
	while((c = getchar()) != EOF){
		if (c != '\t' && c != '\n' && c != '\r' && c != ' '){ // \r is needed for windows files
			++counts[c];
		}
	}
	for (i=0; i < MAX; i++){
		if(counts[i] > 0){
			printf("%2c |", i);
			for (j=0; j < counts[i]; j++){
				putchar('*');
			}
			putchar('\n');
		}
	}
}