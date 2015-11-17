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