/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.
 */
#include "stdio.h"

double countLine();

main(){
	double lineLength, textLength = 0;
	while((lineLength = countLine()) > 0){
		textLength += lineLength;
		printf("%.0f\n", lineLength);
	}
	printf("Text length: %.0f\n", textLength);
}

double countLine(){
	char c;
	double count = 0;
	while((c = getchar()) != EOF && c != '\n' && c != '\r'){
		++count;
	}
	if(c == '\n' || c == '\r'){
		++count;
	}
	return count;
}