/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 Vertical Version:
 */
#include "stdio.h"

#define OUT 0
#define IN 1
#define MAX 1000

main(){
	char c;
	int state = OUT;
	int counts[MAX];
	int count, i, j, maxHor, maxVer;
	count = i = j = maxHor = maxVer = 0;
	//initialize counts
	for (i=0; i < MAX; i++){
		counts[i] = 0;
	}
	while((c = getchar()) != EOF){
		if (c == '\t' || c == '\n' || c == '\r' || c == ' '){ // \r is needed for windows files
			if (state == IN){
				++counts[count];
				if(count > maxHor){
					maxHor = count;
				}
				if(counts[count] > maxVer){
					maxVer = counts[count];
				}
				count = 0;
			}
			state = OUT;
		} else {
			++count;
			state = IN;
		}
	}
	if (state == IN){ //this check is needed for files that do not have new line at end
		++counts[count];
		if(count > maxHor){
			maxHor = count;
		}
		if(counts[count] > maxVer){
			maxVer = counts[count];
		}
		count = 0;
	}
	for (i=1; i <= maxVer; i++){
		for (j=1; j <= maxHor; j++){
			if(counts[j] >= maxVer - i + 1){
				printf("%3c", '*');
			}
			else{
				printf("%3c", ' ');	
			}
		}
		putchar('\n');
	}

	for(i=1;i<=maxHor;i++){
		printf("%3c", '-');
	}
	putchar('\n');
	for(i=1;i<=maxHor;i++){
		printf("%3d", i);
	}

}